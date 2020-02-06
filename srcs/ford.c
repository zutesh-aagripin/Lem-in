/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:50:29 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 21:31:17 by cmissy           ###   ########.fr       */
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
	dist[graph->start] = 0;
	occ[graph->start] = 100;
	occ[graph->finish] = 100;
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

int				ford(char *occ, int *dist, int *prev, t_graph *g)
{
	t_edges	*c;
	int		flag;

	flag = 1;
	init_dist_prev_occ(g, dist, prev, occ);
	while (flag)
	{
		c = g->edges;
		flag = 0;
		while (c)
		{
			if (g->matrix[c->from][c->to] != 0 && dist[c->from] < INF)
			{
				if (!(prev[c->from] >= 0 &&
				g->matrix[prev[c->from]][c->from] > 99 &&
				occ[c->from] < 99 && g->matrix[c->from][c->to] > 99) &&
				relax_vertex(g, dist, prev, c))
					flag = 1;
			}
			c = c->next;
		}
	}
	if (prev[g->finish] == -1)
		return (0);
	return (1);
}
