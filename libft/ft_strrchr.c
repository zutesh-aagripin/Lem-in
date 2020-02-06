/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:29:49 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/24 12:15:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str != '\0')
		str++;
	while (str >= s)
	{
		if (*str == (char)c)
			return (str);
		str--;
	}
	return (NULL);
}
