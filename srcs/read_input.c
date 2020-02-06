/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:35:28 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/30 21:17:31 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_graph		*fill_matrix_names_or_read(t_graph *graph, char *line)
{
	if (graph)
	{
		make_matrix(graph);
		graph->names = make_names(graph->verts);
	}
	while (get_next_line(0, &line))
		free(line);
	return (graph);
}

void		put_the_room(t_graph *graph, char *line, int *num_room)
{
	char	*name;
	char	*tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
	name = ft_strdup(line);
	*tmp = ' ';
	push_vert_front(&graph->verts, name);
	*num_room += 1;
}

void		put_the_link(t_graph *graph, char *line, int num_room)
{
	char		*first;
	char		*second;
	t_verts		*first_vert;
	t_verts		*second_vert;

	if (graph->num_of_rooms == -1)
		graph->num_of_rooms = num_room;
	first = line;
	second = ft_strchr(first, '-');
	*second = '\0';
	second++;
	first_vert = find_vert(graph->verts, first);
	second_vert = find_vert(graph->verts, second);
	push_edges_front(&graph->edges, first_vert->num, second_vert->num);
	second[-1] = '-';
}

int			handle_comments(char *line, char *marker)
{
	if (!ft_strcmp(line, "##start"))
	{
		*marker = START;
		return (1);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		*marker = FINISH;
		return (1);
	}
	else if (line[0] == '#' && line[1] != '#')
	{
		*marker = NONE;
		return (1);
	}
	return (0);
}

t_graph		*read_input(void)
{
	t_graph		*graph;
	char		*line;
	int			num_room;
	char		marker;

	if (get_next_line(0, &line) <= 0)
		return (NULL);
	graph = init_graph(line);
	num_room = 0;
	marker = 0;
	while (graph && get_next_line(0, &line))
	{
		push_line_back(graph->input, line);
		if (line[0] == '#' && handle_comments(line, &marker))
			;
		else if (is_it_a_room(graph, line, &marker, num_room))
			put_the_room(graph, line, &num_room);
		else if (is_it_a_link(graph, line) && !marker)
			put_the_link(graph, line, num_room);
		else
			free_graph(&graph);
	}
	return (fill_matrix_names_or_read(graph, line));
}
