#include "libft.h"

void	ft_strdel(char **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
