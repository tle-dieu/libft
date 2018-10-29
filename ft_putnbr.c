#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_putchar('-');
		abs = -n;
	}
	else
		abs = n;
	if (abs > 9)
		ft_putnbr(abs / 10);
	ft_putchar(abs % 10 + 48);
}
