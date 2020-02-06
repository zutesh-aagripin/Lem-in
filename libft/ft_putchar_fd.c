/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:40:12 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/26 20:07:08 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	octet1;
	unsigned char	octet2;

	if (fd >= 0)
	{
		if (c < 0)
		{
			octet1 = ((unsigned char)c >> 6) | 192;
			octet2 = ((unsigned char)c & 63) | 128;
			write(fd, &octet1, 1);
			write(fd, &octet2, 1);
		}
		else
			write(fd, &c, 1);
	}
}
