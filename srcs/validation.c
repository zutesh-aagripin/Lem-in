/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:43:13 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 15:53:06 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int			check_coordinates(char *x_str, char *y_str)
{
	int		x;
	int		y;
	char	tmp;

	if (((x = ft_atoi(x_str + 1)) == -1 && x_str[1] != '-') ||
	(x == 0 && x_str[1] == '-'))
		return (0);
	if (((y = ft_atoi(y_str + 1)) == -1 && y_str[1] != '-') ||
	(y == 0 && y_str[1] == '-'))
		return (0);
	tmp = *y_str;
	*y_str = 0;
	if (!ft_all_isdigit(y_str + 1) || !ft_all_isdigit(x_str + 1))
	{
		*y_str = tmp;
		return (0);
	}
	*y_str = tmp;
	return (1);
}

int			is_it_a_room(t_graph *graph, char *line, char *marker, int num_room)
{
	char	*x_str;
	char	*y_str;

	if ((*marker == START && graph->start >= 0) ||
	(*marker == FINISH && graph->finish >= 0) ||
	num_room == graph->num_of_rooms)
		return (0);
	y_str = NULL;
	if ((x_str = ft_strchr(line, ' ')))
		y_str = ft_strchr(x_str + 1, ' ');
	if (!y_str || !x_str || ft_strchr(y_str + 1, ' '))
		return (0);
	*x_str = 0;
	if (!check_coordinates(x_str, y_str) ||
	room_is_dublicated(graph->verts, line))
		return (0);
	if (*marker == START)
		graph->start = num_room;
	else if (*marker == FINISH)
		graph->finish = num_room;
	*x_str = ' ';
	*marker = 0;
	return (1);
}

int			is_it_a_link(t_graph *graph, char *line)
{
	t_verts		*first_vert;
	t_verts		*second_vert;
	char		*first;
	char		*second;

	if (graph->start == -1 || graph->finish == -1 ||
	!(second = ft_strchr(line, '-')) || ft_strchr(second + 1, '-') ||
	ft_strchr(line, ' '))
		return (0);
	*second = '\0';
	second++;
	first = line;
	if (!(first_vert = find_vert(graph->verts, first)) ||
	!(second_vert = find_vert(graph->verts, second)) ||
	first_vert == second_vert ||
	edges_is_dublicated(graph->edges, first_vert->num, second_vert->num))
	{
		second[-1] = '-';
		return (0);
	}
	second[-1] = '-';
	return (1);
}
