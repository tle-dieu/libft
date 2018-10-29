#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (1);
	if (s1 && s2)
	{
		while (*s1 == *s2)
		{
			if (!--n || (!*s1 && !*s2))
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}
