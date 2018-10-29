#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	if (p_dest > p_src)
		while (n-- > 0)
			p_dest[n] = p_src[n];
	else
		while (i++ < n)
			p_dest[i - 1] = p_src[i - 1];
	return (dest);
}
