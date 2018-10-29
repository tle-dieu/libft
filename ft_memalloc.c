#include "libft.h"

void    *ft_memalloc(size_t size)
{
    void *new_tab;
    
	if (!(new_tab = malloc(size)))
			return (NULL);
	ft_bzero(new_tab, size);
    return (new_tab); 
}
