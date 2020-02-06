/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:23:14 by aagripin          #+#    #+#             */
/*   Updated: 2020/01/31 14:28:43 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_graph		*graph;

	if (!(graph = read_input()))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		if (graph->matrix && graph->edges)
			algorithm(graph);
		else
			write(1, "Error\n", 6);
		free_graph(&graph);
	}
	return (0);
}
