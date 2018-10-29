#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (i == 0 || src[i - 1])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
