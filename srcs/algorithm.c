/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:31:54 by cmissy            #+#    #+#             */
/*   Updated: 2020/02/03 13:42:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		restore_shortest_path(char *occ, int *prev, int path_num,
t_graph *graph)
{
	int i;
	int j;

	j = 0;
	i = graph->finish;
	while (i != graph->start)
	{
		if (graph->matrix[prev[i]][i] == 0 || graph->matrix[i][prev[i]] == 0)
		{
			graph->matrix[i][prev[i]] = 100;
			graph->matrix[prev[i]][i] = 0;
		}
		else
		{
			graph->matrix[prev[i]][i] = 0;
			graph->matrix[i][prev[i]] = -1;
		}
		if (occ[prev[i]] < 100)
			j--;
		if (occ[prev[i]] > path_num + 51)
			occ[prev[i]] = path_num + 51;
		i = prev[i];
		j++;
	}
	return (j);
}

int		recover_matrix(int *prev, t_graph *graph, char *occ)
{
	int i;
	int j;

	j = 0;
	i = graph->finish;
	while (i != graph->start)
	{
		graph->matrix[prev[i]][i] = 100;
		graph->matrix[i][prev[i]] = 100;
		occ[prev[i]] = 100;
		i = prev[i];
		j++;
	}
	return (j);
}

int		old_paths_better(t_graph *graph, int power, int i, int *best_lines)
{
	int		lines;

	lines = (graph->num_of_ants + power) / i;
	if (graph->num_of_ants % i > 0 || power % i)
		lines += 1;
	if (*best_lines > lines)
	{
		*best_lines = lines;
		return (0);
	}
	else if (*best_lines < lines)
		return (1);
	return (0);
}

int		find_optimal_paths(t_graph *graph, char *occ, int *dist, int *prev)
{
	int			best[graph->num_of_rooms];
	int			best_lines;
	int			i;
	int			j;
	int			power;

	i = 0;
	power = 0;
	best_lines = INF;
	while (i < graph->num_of_rooms)
		occ[i++] = 100;
	i = 0;
	while (ford(occ, dist, prev, graph) && i < graph->num_of_ants && (j = -1))
	{
		power = power + restore_shortest_path(occ, prev, i++, graph);
		if (old_paths_better(graph, power, i, &best_lines))
		{
			recover_matrix(prev, graph, occ);
			restore_shortest_path(occ, best, i - 2, graph);
			break ;
		}
		while (++j < graph->num_of_rooms)
			best[j] = prev[j];
	}
	return (i);
}

void	algorithm(t_graph *graph)
{
	char		occ[graph->num_of_rooms];
	int			dist[graph->num_of_rooms];
	int			prev[graph->num_of_rooms];
	t_path		*paths[50];
	int			i;

	if (!find_optimal_paths(graph, occ, dist, prev))
	{
		print_input_struct(graph->input);
		write(2, "NO PATHS\n", 9);
		return ;
	}
	i = 0;
	while (i < graph->num_of_rooms)
		occ[i++] = 0;
	i = 0;
	while (reverse_ford(occ, dist, prev, graph))
	{
		paths[i] = restore_path(occ, prev, i, graph);
		i++;
	}
	ft_output(paths, i, graph);
	free_paths(paths, i);
}
