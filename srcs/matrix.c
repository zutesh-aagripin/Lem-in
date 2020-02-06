/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:27:36 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 16:00:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		free_matrix(char ***matrix, int num_of_rooms)
{
	int			i;

	if (!*matrix)
		return ;
	i = 0;
	while (i < num_of_rooms)
		free((*matrix)[i++]);
	free(*matrix);
	*matrix = NULL;
}

void		ft_fill_matrix(char **matrix, t_edges *links)
{
	t_edges		*tmp;

	tmp = links;
	while (tmp)
	{
		matrix[tmp->from][tmp->to] = 100;
		tmp = tmp->next;
	}
}

int			ft_matrix_len(t_verts *rooms)
{
	if (!rooms)
		return (0);
	while (rooms->next)
		rooms = rooms->next;
	return (rooms->num + 1);
}

void		make_matrix(t_graph *graph)
{
	int			i;

	i = 0;
	if (graph->num_of_rooms > 0)
	{
		graph->matrix = ft_memalloc(sizeof(char*) * graph->num_of_rooms);
		while (i < graph->num_of_rooms)
		{
			graph->matrix[i] = ft_memalloc(sizeof(char) * graph->num_of_rooms);
			i++;
		}
		ft_fill_matrix(graph->matrix, graph->edges);
	}
}
