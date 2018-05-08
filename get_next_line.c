/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:55:50 by ikotvits          #+#    #+#             */
/*   Updated: 2018/04/18 13:56:01 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

t_gnl		*ft_find_fd(t_gnl *gnl, int fd)
{
	while (gnl->next_fd && fd != gnl->fd)
		gnl = gnl->next_fd;
	if (fd != gnl->fd)
	{
		if (!(gnl->next_fd = (t_gnl *)malloc(sizeof(t_gnl))))
			return (NULL);
		gnl->next_fd->fd = fd;
		gnl->next_fd->next_fd = NULL;
		gnl->next_fd->next = NULL;
		gnl->next_fd->strres = NULL;
		gnl->next_fd->b = ft_strnew(BUFF_SIZE);
		gnl = gnl->next_fd;
	}
	return (gnl);
}

int			ft_help(t_gnl *gnl, int fd, char **line)
{
	if (gnl->next)
	{
		gnl->strres = ft_strdup(gnl->next);
		ft_strdel(&gnl->next);
	}
	while (read(fd, gnl->b, BUFF_SIZE) > 0)
	{
		gnl->temp = gnl->strres;
		gnl->strres = ft_strjoin(gnl->strres, gnl->b);
		free(gnl->temp);
		ft_strclr(gnl->b);
		if (ft_strchr(gnl->strres, '\n'))
			break ;
	}
	if ((gnl->n = ft_strchr(gnl->strres, '\n')))
	{
		*gnl->n = '\0';
		*line = ft_strdup(gnl->strres);
		gnl->next = ft_strdup(gnl->n + 1);
		ft_strclr(gnl->b);
		ft_strdel(&gnl->strres);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static	t_gnl	*pgnl;
	t_gnl			*gnl;

	if (fd == -1 || !line || read(fd, 0, 0) < 0 || BUFF_SIZE < 1 || fd > 256)
		return (-1);
	if (!pgnl)
	{
		ERR((pgnl = (t_gnl *)malloc(sizeof(t_gnl))));
		INIT(pgnl);
	}
	gnl = ft_find_fd(pgnl, fd);
	if (ft_help(gnl, fd, line))
		return (1);
	if (!gnl->strres || *gnl->strres == 0)
		return (0);
	*line = ft_strdup(gnl->strres);
	ft_strdel(&gnl->strres);
	gnl->next = ft_strdup("\0");
	return (1);
}
