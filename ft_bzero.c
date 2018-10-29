#include "libft.h"

void	ft_bzero(void *s, int n)
{
	unsigned char *temp;

	temp = (unsigned char*)s;
	while (n)
		temp[--n] = 0;
}
