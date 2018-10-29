#include "libft.h"

char	*ft_strdup(const char *s)
{
    char    *new;
    size_t  i;
 
    i = 0;
    if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
    	return (NULL);
    while (*s)
		new[i++] = *s++;
    new[i] = '\0';
    return (new);
}
