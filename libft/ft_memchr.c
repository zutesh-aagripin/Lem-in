/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:48:12 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/17 17:54:13 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sym;

	sym = (unsigned char*)s;
	while (n > 0)
	{
		if ((unsigned char)c == *sym)
			return (sym);
		sym++;
		n--;
	}
	return (NULL);
}
