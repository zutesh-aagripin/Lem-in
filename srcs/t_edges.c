/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_edges.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:30:40 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 14:30:30 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		free_edges(t_edges **edges)
{
	t_edges		*tmp;
	t_edges		*current;

	current = *edges;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*edges = NULL;
}

int			edges_is_dublicated(t_edges *edges, int first, int second)
{
	t_edges		*tmp;

	tmp = edges;
	while (tmp)
	{
		if ((tmp->from == first && tmp->to == second) ||
		(tmp->from == second && tmp->to == first))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		push_edges_front(t_edges **edges, int first, int second)
{
	t_edges		*new;

	new = ft_memalloc(sizeof(t_edges));
	new->from = first;
	new->to = second;
	new->next = ft_memalloc(sizeof(t_edges));
	new->next->from = second;
	new->next->to = first;
	new->next->next = NULL;
	if (*edges)
		new->next->next = *edges;
	*edges = new;
}
