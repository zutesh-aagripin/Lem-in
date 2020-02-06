/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:06:24 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 21:39:59 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_num_w(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			if (!(res[i++] = ft_push_w((char*)s, c)))
				return (NULL);
		while (*s && *s != c)
			s++;
	}
	res[i] = 0;
	return (res);
}
