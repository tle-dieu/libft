/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:21:42 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/12 15:56:35 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
			words++;
		while (*s != c && *s)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;
	size_t	j;
	size_t	occ;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		occ = i;
		while (s[i] != c && s[i])
			i++;
		split[j++] = ft_strsub(s, occ, i - occ);
	}
	split[j] = NULL;
	return (split);
}
