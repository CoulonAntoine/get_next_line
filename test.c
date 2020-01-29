/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:04:56 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/29 12:01:04 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr(char *s)
{
	if (!s)
		ft_putstr("~ null");
	write(1, s, ft_strlen(s));
}

static void	ft_putnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar_fd((char)nbr + '0', 1);
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	if (ac > 2)
	{
		ft_putstr("~ Please enter the file path.\n");
		return (0);
	}
	else if (ac == 2 && (fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("~ The file could not be opened.\n");
		return (0);
	}
	else
		fd = 0;
	
	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_putnbr(i++);
		ft_putstr(" *** |");
		ft_putstr(line);
		ft_putstr("|\n");
		free(line);
	}
	ft_putnbr(i++);
	ft_putstr(" *** |");
	ft_putstr(line);
	ft_putstr("|\n");
	free(line);
	if (ret == 0)
		ft_putstr("~ EOF\n");
	if (ret == -1)
		ft_putstr("~ ERR\n");
	close(fd);
	return (0);
}