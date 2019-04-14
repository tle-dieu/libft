/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dieu <tle-dieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 01:30:38 by tle-dieu          #+#    #+#             */
/*   Updated: 2019/04/14 03:51:03 by tle-dieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			return (-1);
		while (get_next_line(fd, &line) == 1)
		{
			ft_printf("RETURN\n");
			/* ft_printf("%s\n", line); */
			free(line);
			line = NULL;
		}
		close(fd);
	}
	return (0);
}
