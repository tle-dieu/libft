/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:12:09 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/04/15 02:23:00 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char const *search;
	unsigned char		comp;

	search = (unsigned char const *)s;
	comp = (unsigned char)c;
	while (n--)
	{
		if (*search == comp)
			return ((void *)search);
		search++;
	}
	return (NULL);
}
