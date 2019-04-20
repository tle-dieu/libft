/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <tle-dieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:24:59 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/04/20 20:25:45 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s, const char *chr)
{
	const char *tmp;

	while (*s)
	{
		tmp = chr;
		while (*tmp)
			if (*tmp++ == *s)
				return ((char *)s);
		s++;
	}
	return (NULL);
}
