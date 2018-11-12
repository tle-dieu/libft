/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:16:15 by tle-dieu          #+#    #+#             */
/*   Updated: 2018/11/12 12:28:51 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	size_t i;
	size_t j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
			ft_putchar(tab[j][i++]);
		ft_putchar('\n');
		j++;
	}
}
