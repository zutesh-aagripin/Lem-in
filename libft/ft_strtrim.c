/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:17:15 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/24 20:05:41 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	l;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		if (*s == '\0')
			return (ft_strnew(0));
		l = ft_strlen(s) - 1;
		while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
			l--;
		return (ft_strsub(s, 0, l + 1));
	}
	return (NULL);
}
