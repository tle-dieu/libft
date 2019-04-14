/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:37:36 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/04/14 04:16:18 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_gnl	*create_buff(t_gnl *file)
{
	t_buff *new;

	if (!(new = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	new->ret = 0;
	new->next = NULL;
	ft_bzero(new->s, BS_GNL);
	file->prev = file->last;
	if (!file->buff)
		file->buff = new;
	else
		file->last->next = new;
	file->last = new;
	return (file);
}

static t_gnl	*choose_fd(t_gnl **begin_list, int fd)
{
	t_gnl *list;
	t_gnl *new;

	list = *begin_list;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->buff = NULL;
	new->last = NULL;
	new->total_len = 0;
	new->fd = fd;
	new->next = *begin_list;
	new->prev = NULL;
	*begin_list = new;
	return (create_buff(new));
}

void			print_buff(t_gnl *file, t_buff *buff)
{
	int i;

	i = 0;
	while (buff)
	{
		ft_printf("buff %d: '%s'\n", ++i, buff->s);
		buff = buff->next;
	}
	ft_printf("last: '%s'\n", file->last->s);
	ft_printf("\n");
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_gnl	*list;
	t_gnl			*actual;
	char			tmp[1];
	char			*end;

	if (fd < 0 || !line || read(fd, tmp, 0) < 0)
		return (-1);
	if (!(actual = choose_fd(&list, fd)))
		return (-1);
	ret = 0;
	while ((!actual->prev || !(end = ft_memchr(actual->prev->s, '\n', BS_GNL)))
	&& (ret = read(fd, actual->last->s, BS_GNL)) > 0)
	{
		actual->last->ret = ret;
		actual->total_len += ret;
		print_buff(actual, actual->buff);
		if (ret == BS_GNL && !(create_buff(actual)))
			return (-1);
	}
	line = ft_strnew(actual->total_len);
	return (ret != 0);
}
