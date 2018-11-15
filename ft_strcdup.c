/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:23:40 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/15 16:24:48 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strcdup(const char *s, char c)
{
	char *new;
	size_t  i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i))))
		return (NULL);
	new[i] = '\0';
	while (i--)
		new[i] = s[i];
	return (new);
}
