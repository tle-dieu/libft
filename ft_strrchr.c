#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *temp;

    temp = ft_strchr(s, '\0');
    while (temp >= s)
    {
		if (*temp == (unsigned char)c)
    		return ((char*)temp);
		temp--;
    }
    return (NULL);
}
