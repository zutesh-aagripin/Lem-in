/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:37:29 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 21:37:49 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_push_w(char *str, char c)
{
	char		*w;
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(w = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (*str && *str != c)
		w[i++] = *str++;
	return (w);
}
