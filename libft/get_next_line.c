/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:47:24 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/13 18:20:50 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pusher(char **line, char **s, char *tmp, int fd)
{
	if (tmp)
	{
		*line = ft_strsub(s[fd], 0, (tmp++ - s[fd]));
		tmp = ft_strdup(tmp);
	}
	else
		*line = ft_strdup(s[fd]);
	if (!*line)
		return (-1);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*s[255];
	char			buff[BUFF_SIZE + 1];
	int				status;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		tmp = NULL;
	else
		tmp = ft_strchr(s[fd], '\n');
	while (!tmp && (status = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[status] = '\0';
		if (!s[fd])
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		tmp = ft_strchr(s[fd], '\n');
	}
	if (s[fd] && s[fd][0])
		return (ft_pusher(line, s, tmp, fd));
	return (0);
}
