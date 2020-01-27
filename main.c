/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:04:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/27 15:06:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	ft_putstr(char *s)
{
	if (!s)
		ft_putstr("~ null");
	write(1, s, ft_strlen(s));
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;
	
	if (ac != 2)
	{
		ft_putstr("~ Please enter the file path.\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("~ The file could not be opened.\n");
		return (0);
	}
	ret = get_next_line(fd, &line);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	ft_putstr(line);
	ft_putstr("\n");
	if (ret == 0)
		ft_putstr("~ EOF\n");
	if (ret == -1)
		ft_putstr("~ ERR\n");
	return (0);
}