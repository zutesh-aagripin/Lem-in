/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:16:31 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/23 18:11:33 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;

	if (!*haystack && !*needle)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		h = (char*)haystack;
		n = (char*)needle;
		while (*n != '\0' && *n == *h)
		{
			n++;
			h++;
		}
		if (*n == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
