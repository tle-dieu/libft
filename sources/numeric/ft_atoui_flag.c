/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:08:20 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/05/31 16:10:32 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atoui_flag(char **nbr, int *error, int f, char *stop)
{
	unsigned long long	result;
	char				*s;
	int					overflow;

	s = *nbr;
	overflow = 0;
	*error = 0;
	result = 0;
	if (!(AT_NOSPACE & f))
		while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
			s++;
	s += (!(f & AT_NOSIGN) && *s == '+') ? 1 : 0;
	while ((*s >= '0' && *s <= '9') && (!(f & AT_STOP) || !ft_strchr(stop, *s)))
	{
		if (result * 10 + *s++ - 48 < result)
			overflow = 1;
		result = result * 10 + *s++ - 48;
	}
	if ((AT_NOOVERFLOW & f && ((!(AT_LONG & f) && result > 2147483647)
				|| overflow)) || (AT_ONLYNUM & f && (!ft_isdigit(*s)
				&& (!(AT_STOP & f) || !ft_strchr(stop, *s)))))
		*error = 1;
	if (AT_INCREM & f && (!(AT_NOERR & f) || !*error))
		*nbr = s;
	return (AT_LONG & f ? (long long)result : (unsigned)result);
}
