/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:46:51 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/30 18:23:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (!*s1 && !*s2)
			return (1);
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n > 0)
		{
			s1++;
			s2++;
			n--;
		}
		if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
			return (1);
	}
	return (0);
}
