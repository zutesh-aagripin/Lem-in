/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:46:28 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/24 18:27:03 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				fresh[i] = f(s[i]);
				i++;
			}
			return (fresh);
		}
	}
	return (NULL);
}
