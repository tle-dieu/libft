#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		abs = -n;
	}
	else
		abs = n;
	if (abs > 9)
		ft_putnbr_fd(abs / 10, fd);
	ft_putchar_fd(abs % 10 + 48, fd);
}
