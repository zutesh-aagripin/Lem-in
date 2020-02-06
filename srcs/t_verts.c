/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_verts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:18:16 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 14:29:52 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		free_verts(t_verts **last)
{
	t_verts		*tmp;
	t_verts		*current;

	current = *last;
	while (current)
	{
		tmp = current->next;
		free(current->name);
		free(current);
		current = tmp;
	}
	*last = NULL;
}

t_verts		*find_vert(t_verts *first, char *str)
{
	t_verts		*tmp;

	tmp = first;
	while (tmp && ft_strcmp(tmp->name, str))
		tmp = tmp->next;
	return (tmp);
}

void		push_vert_front(t_verts **first, char *str)
{
	t_verts		*new;

	new = ft_memalloc(sizeof(t_verts));
	new->name = str;
	new->num = 0;
	new->next = NULL;
	if (*first)
	{
		new->next = *first;
		new->num = (*first)->num + 1;
	}
	*first = new;
}

int			room_is_dublicated(t_verts *last, char *room)
{
	t_verts		*tmp;

	tmp = last;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, room))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
