/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:49:43 by cmissy            #+#    #+#             */
/*   Updated: 2019/04/26 15:55:30 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	if (fd >= 0)
	{
		{
			num = (long)n;
			if (n < 0)
			{
				write(fd, "-", 1);
				num *= -1;
			}
			if (num / 10)
				ft_putnbr_fd((int)(num / 10), fd);
			c = num % 10 + '0';
			write(fd, &c, 1);
		}
	}
}
