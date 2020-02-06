/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:40:28 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/17 21:19:50 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		ln;

	ln = 0;
	while (s1[ln])
		ln++;
	res = (char*)malloc(sizeof(char) * (ln + 1));
	if (!res)
		return (NULL);
	res[ln] = '\0';
	ln--;
	while (ln >= 0)
	{
		res[ln] = s1[ln];
		ln--;
	}
	return (res);
}
