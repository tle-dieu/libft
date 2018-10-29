#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *temp;
	unsigned char t;
    
    temp = (unsigned char*)s;
	t = (unsigned char)c;
    while (n > 0)
    	temp[--n] = t;
    return (s);
}
