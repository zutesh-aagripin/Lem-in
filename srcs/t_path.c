/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:31:54 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 22:12:49 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	free_paths(t_path **paths, int num_of_paths)
{
	t_path *ptr;
	t_path *tmp;

	while (--num_of_paths >= 0)
	{
		ptr = paths[num_of_paths];
		while (ptr)
		{
			tmp = ptr->next;
			free(ptr);
			ptr = NULL;
			ptr = tmp;
		}
	}
}

t_path	*ft_create_path(int i)
{
	t_path	*elem;

	if (!(elem = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	elem->vert_num = i;
	elem->next = NULL;
	return (elem);
}

void	path_push_back(t_path **path, int i)
{
	t_path	*elem;

	if (path && *path)
	{
		elem = *path;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_path(i);
	}
	else
		*path = ft_create_path(i);
}

int		calculate_moves(t_path *way)
{
	int		moves;
	t_path	*ptr;

	ptr = way;
	moves = 0;
	while (ptr)
	{
		ptr = ptr->next;
		moves++;
	}
	return (moves);
}

t_path	*restore_path(char *occ, int *prev, int path_num, t_graph *graph)
{
	int		i;
	t_path	*way;

	way = NULL;
	i = graph->start;
	while (i != graph->finish)
	{
		graph->matrix[prev[i]][i] = 0;
		graph->matrix[i][prev[i]] = 1;
		i = prev[i];
		occ[i] = path_num + 1;
		path_push_back(&way, i);
	}
	return (way);
}
