/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:26:36 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 14:29:39 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char		**make_names(t_verts *verts)
{
	t_verts		*tmp;
	char		**names;

	if (!verts)
		return (NULL);
	names = ft_memalloc(sizeof(char*) * (verts->num + 1));
	tmp = verts;
	while (tmp)
	{
		names[tmp->num] = tmp->name;
		tmp = tmp->next;
	}
	return (names);
}

void		free_names(char ***names)
{
	if (*names)
		free(*names);
	*names = NULL;
}
