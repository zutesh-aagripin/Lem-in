/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:44:28 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/23 12:36:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (n > 0)
	{
		*d++ = *s++;
		if (*(d - 1) == (unsigned char)c)
			return ((void*)d);
		n--;
	}
	return (NULL);
}
