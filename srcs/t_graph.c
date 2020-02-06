/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_graph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:31:26 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 15:37:15 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void			free_graph(t_graph **graph)
{
	if (!(*graph))
		return ;
	free_input_struct(&(*graph)->input);
	free_matrix(&(*graph)->matrix, (*graph)->num_of_rooms);
	free_edges(&(*graph)->edges);
	free_verts(&(*graph)->verts);
	free_names(&(*graph)->names);
	free((*graph));
	*graph = NULL;
}

t_graph			*init_graph(char *line)
{
	t_graph		*graph;
	int			num_of_ants;

	if ((num_of_ants = ft_atoi(line)) <= 0 || !ft_all_isdigit(line))
		return (NULL);
	graph = ft_memalloc(sizeof(t_graph));
	graph->input = ft_memalloc(sizeof(t_input));
	graph->verts = NULL;
	graph->matrix = NULL;
	graph->names = NULL;
	graph->edges = NULL;
	graph->num_of_rooms = -1;
	graph->num_of_ants = num_of_ants;
	graph->start = -1;
	graph->finish = -1;
	graph->input->line = line;
	graph->input->next = NULL;
	return (graph);
}
