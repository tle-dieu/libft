/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:09:18 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/01/16 17:25:23 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	color_in_buff(t_print *buff, char *color)
{
	if (buff->i + 25 >= BUFF_LEN)
		empty_buff(buff);
	while (*color)
		buff->str[buff->i++] = *color++;
}

void	field_in_buff(t_print *buff, int width, char zero)
{
	char c;

	c = ' ' + zero;
	if (buff->i + width >= BUFF_LEN || width + buff->i < 0)
	{
		while (--width >= 0)
		{
			if (buff->i >= BUFF_LEN)
				empty_buff(buff);
			buff->str[buff->i++] = c;
		}
	}
	else
	{
		while (--width >= 0)
			buff->str[buff->i++] = c;
	}
}

void	empty_buff(t_print *buff)
{
	int i;

	i = buff->i;
	buff->i = 0;
	buff->total += (int)write(1, buff->str, i);
	if (buff->total < 0)
		buff->error = 1;
}
