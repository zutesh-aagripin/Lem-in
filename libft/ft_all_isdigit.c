/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:27:07 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 22:19:58 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_all_isdigit(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
