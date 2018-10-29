#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (dest[i])
		i++;
	n += i; 
	while (*src && i < n) 
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
