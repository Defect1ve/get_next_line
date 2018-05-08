/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:01:24 by ikotvits          #+#    #+#             */
/*   Updated: 2018/05/02 21:21:38 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define ERR(e) if (!e) return (-1);

# define INIT1(gnl) gnl->fd = fd; gnl->next_fd = NULL; gnl->strres = NULL;
# define INIT2(gnl) gnl->next = NULL; gnl->b = ft_strnew(BUFF_SIZE + 1);
# define INIT(gnl) INIT1(gnl); INIT2(gnl);
# include <unistd.h>
# include "./libft/libft.h"

typedef struct		s_gnl
{
	char			*strres;
	char			*b;
	char			*temp;
	char			*next;
	char			*n;
	int				fd;
	struct s_gnl	*next_fd;
}					t_gnl;
int					get_next_line(const int fd, char **line);

#endif
