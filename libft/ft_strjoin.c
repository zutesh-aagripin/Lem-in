/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:04:30 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/26 20:09:01 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (s1 && s2)
	{
		fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (fresh)
		{
			ft_strcat(fresh, s1);
			ft_strcat(fresh, s2);
			return (fresh);
		}
	}
	return (NULL);
}
