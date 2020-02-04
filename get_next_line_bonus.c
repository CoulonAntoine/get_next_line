/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:15:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/04 11:20:05 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	ft_findnl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return ((str[i] == '\n') ? i : -1);
}

static int	ft_retrieve_rest(char **rest, char **line)
{
	int		i;
	char	*tmp;

	if (!*rest)
	{
		if (!(*line = ft_calloc(1, 1)))
			return (-1);
		return (0);
	}
	tmp = *rest;
	i = (ft_findnl(tmp) > -1) ? ft_findnl(tmp) : (ft_strlen(tmp) + 1);
	if (!(*line = ft_substr(tmp, 0, i)))
		return (-1);
	if ((int)ft_strlen(tmp) > i && tmp[i] == '\n')
	{
		if (!(*rest = ft_substr(tmp, ++i, ft_strlen(tmp))))
			return (-1);
		free(tmp);
		return (1);
	}
	free(tmp);
	*rest = NULL;
	return (0);
}

static int	ft_manage_nl(char *buffer, char **line, char **rest, int i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = *line;
	if (!(tmp2 = ft_substr((char *)buffer, 0, i)))
		return (0);
	if (!(*line = ft_strjoin(tmp1, tmp2)))
		return (-1);
	free(tmp1);
	free(tmp2);
	tmp1 = *rest;
	if (!(tmp2 = ft_substr((char *)buffer, ++i, ft_strlen((char *)buffer))))
		return (-1);
	if (!(*rest = ft_strjoin(tmp1, tmp2)))
		return (-1);
	free(tmp1);
	free(tmp2);
	return (1);
}

static int	ft_read(int fd, char **rest, char **line)
{
	int		i;
	int		offset;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	while ((offset = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = *line;
		buffer[offset] = '\0';
		if ((i = ft_findnl(((char *)buffer))) >= 0)
			return (ft_manage_nl((char *)buffer, line, rest, i));
		if (!(*line = ft_strjoin(tmp, (char *)buffer)))
			return (-1);
		free(tmp);
	}
	return (offset);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
	read(fd, 0, 0) || fd >= OPEN_MAX)
		return (RET_ERR);
	if ((ret = ft_retrieve_rest(&(rest[fd]), line)) == -1)
		return (RET_ERR);
	if (!ret)
	{
		if ((ret = ft_read(fd, &(rest[fd]), line)) == -1)
			return (RET_ERR);
		return (ret);
	}
	else
		return (RET_RED);
}
