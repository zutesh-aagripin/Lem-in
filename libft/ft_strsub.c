/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:52:26 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/24 19:11:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s)
	{
		sub = ft_strnew(len);
		if (sub)
		{
			s = s + start;
			while (i < len)
			{
				sub[i] = s[i];
				i++;
			}
			return (sub);
		}
	}
	return (NULL);
}
