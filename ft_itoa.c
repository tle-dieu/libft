#include "libft.h"

static size_t	count_dec(int nb, size_t *dec)
{
	unsigned int	abs;
	size_t			len;

	len = 1;
	if (nb < 0)
	{
		len++;
		abs = -nb;
	}
	else
		abs = nb;
	while (abs > 9)
	{
		len++;
		*dec *= 10;
		abs /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	size_t			dec;
	size_t			i;
	unsigned int	abs;
	
	i = 0;
	dec = 1;
	if (!(nbr = (char *)malloc(sizeof(char) * (count_dec(n, &dec) + 1))))
		return (NULL);
	if (n < 0)
	{
		nbr[i++] = '-';
		abs = -n;
	}
	else
		abs = n;
	while (dec)
	{
		nbr[i++] = abs / dec % 10 + 48;
		dec /= 10;
	}
	nbr[i] = '\0';
	return (nbr);
}
