/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:50:29 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 20:43:04 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		init_dist_prev_occ(t_graph *graph, int *dist, int *prev,
char *occ)
{
	int		i;

	i = 0;
	while (i < graph->num_of_rooms)
	{
		dist[i] = INF;
		prev[i] = -1;
		i++;
	}
	dist[graph->finish] = 0;
	occ[graph->start] = 0;
	occ[graph->finish] = 0;
}

static int		relax_vertex(t_graph *graph, int *dist, int *prev,
t_edges *curr_edge)
{
	int		a;
	int		b;

	a = curr_edge->from;
	b = curr_edge->to;
	if ((dist[b] > graph->matrix[a][b] + dist[a]))
	{
		dist[b] = dist[a] + graph->matrix[a][b];
		prev[b] = a;
		return (1);
	}
	return (0);
}

int				reverse_ford(char *occ, int *dist, int *prev, t_graph *graph)
{
	int		a;
	int		b;
	t_edges	*curr_edge;
	int		flag;

	flag = 1;
	init_dist_prev_occ(graph, dist, prev, occ);
	while (flag)
	{
		curr_edge = graph->edges;
		flag = 0;
		while (curr_edge)
		{
			a = curr_edge->from;
			b = curr_edge->to;
			if (!occ[a] && graph->matrix[a][b] != 0 && dist[a] < INF && !occ[b])
				if (relax_vertex(graph, dist, prev, curr_edge))
					flag = 1;
			curr_edge = curr_edge->next;
		}
	}
	if (prev[graph->start] == -1)
		return (0);
	else
		return (1);
}
