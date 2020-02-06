/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 02:52:52 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 17:02:35 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (!lst || !f || !(new = f(lst)))
		return (NULL);
	lst = lst->next;
	tmp = new;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
		{
			while (new)
			{
				ft_lstdel(&new, &ft_bzero);
				new = new->next;
			}
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (new);
}
