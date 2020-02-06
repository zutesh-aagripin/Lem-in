/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:00:49 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 21:27:38 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpush(t_list *alst, t_list *new)
{
	t_list		*tmp;

	if (!alst || !new)
		return ;
	tmp = alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
