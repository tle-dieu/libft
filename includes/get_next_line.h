/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:27:49 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/04/14 04:10:40 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
/* # define BS_GNL 100 */
# define BS_GNL 3

typedef struct		s_buff
{
	int				ret;
	char			s[BS_GNL + 1]; //enlever + 1
	struct s_buff	*next;
}					t_buff;

typedef struct		s_gnl
{
	t_buff			*buff;
	t_buff			*last;
	t_buff			*prev;
	int				total_len;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

#endif
