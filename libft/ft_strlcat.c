/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:21:08 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/23 16:08:27 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	size_t		slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (size + slen);
	ft_strncat(dst, src, (size - dlen - 1));
	return (slen + dlen);
}
