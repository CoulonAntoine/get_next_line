/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:15:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/27 15:09:53 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_findnl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	ft_retrieve_rest(char **rest, char **line)
{
	char	*tmp;
	
	if (!*rest)
	{
		*line = NULL;
		return (0);
	}
	tmp = *rest;
	if (!(*line = ft_substr(tmp, 0, ft_findnl(tmp))))
		return (-1);
	if (ft_strlen(tmp) > (ft_findnl(tmp) + 1))
	{
		if (!(*rest = ft_substr(tmp, (ft_findnl(tmp) + 1), ft_strlen(tmp))))
			return (-1);
		free(tmp);
		return (1);
	}
	free(tmp);
	*rest = NULL;
	return (0);
}

static int	ft_retrieve_fd(int fd, char **rest, char **line)
{
	int		i;
	int		offset;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp1;
	char	*tmp2;

	if ((offset = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	buffer[offset] = '\0';
	i = ft_findnl(tmp1);
	if (!(tmp1 = ft_substr((char *)buffer, 0, i)))
		return (-1);
	tmp2 = *line;
	if (!(*line = ft_strjoin(tmp2, tmp1)))
		return (-1);
	free(tmp1);
	free(tmp2);
	if (ft_strlen((char *)buffer) > (i + 1))
	{
		tmp1 = *rest;
		if (!(tmp2 = ft_substr((char *)buffer, (i + 1), ft_strlen((char *)buffer))))
			return (-1);
		if (!(*rest = ft_strjoin(tmp1, tmp2)))
			return (-1);
		free(tmp1);
		free(tmp2);
		return (1);
	}
	return ((offset < BUFFER_SIZE) ? RET_EOF : RET_RED);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
	read(fd, 0, 0) || fd >= OPEN_MAX)
		return (RET_ERR);
	if ((ret = ft_retrieve_rest(rest + fd, line)) == -1)
		return (RET_ERR);
	if (!ret)
	{
		if ((ret = ft_retrieve_fd(fd, rest + fd, line)) == -1)
			return (RET_ERR);
		return (ret);
	}else
		return (RET_RED);
}

// int			main(void)
// {
// 	char	*rest;
// 	char	*line;
// 	int		ret;

// 	rest = ft_strdup("hey\ntest");
// 	line = NULL;
// 	ret = ft_retrieve_rest(&rest, &line);
// 	printf("ret: |%d|\nrest: |%s|\nline: |%s|\n", ret, rest, line);
// 	printf("---\n");
// 	ret = ft_retrieve_rest(&rest, &line);
// 	printf("ret: |%d|\nrest: |%s|\nline: |%s|\n", ret, rest, line);
// 	return (0);
// }







