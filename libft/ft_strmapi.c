/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:13:24 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/24 19:12:45 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		i;

	i = 0;
	if (s)
	{
		fresh = ft_strnew(ft_strlen(s));
		if (fresh)
		{
			while (s[i])
			{
				fresh[i] = f(i, s[i]);
				i++;
			}
			return (fresh);
		}
	}
	return (NULL);
}
