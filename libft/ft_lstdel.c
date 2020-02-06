/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 02:18:45 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/27 05:43:18 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr;
	t_list		*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	ptr = *alst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = tmp;
	}
	*alst = NULL;
}
