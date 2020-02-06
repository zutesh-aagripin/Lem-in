/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:25:26 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/30 20:25:29 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		ft_free_links(t_edges **links)
{
	t_edges		*tmp;

	while (*links)
	{
		tmp = *links;
		*links = (*links)->next;
		if (tmp->pair[0])
			free(tmp->pair[0]);
		if (tmp->pair[1])
			free(tmp->pair[1]);
		free(tmp);
	}
	links = NULL;
}

t_edges		*ft_make_link(char *name1, char *name2)
{
	t_edges		*link;

	if (!(link = malloc(sizeof(t_edges))))
		exit(1);
	link->pair[0] = name1;
	link->pair[1] = name2;
	link->next = NULL;
	return (link);
}

void		ft_push_link_back(t_edges **links, t_edges *link)
{
	if (*links)
	{
		if ((*links)->next)
			ft_push_link_back(&(*links)->next, link);
		else
			(*links)->next = link;
	}
	else
		*links = link;
}
