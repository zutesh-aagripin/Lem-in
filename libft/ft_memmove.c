/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:56:52 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/23 11:52:41 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s < d)
	{
		s += len - 1;
		d += len - 1;
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
