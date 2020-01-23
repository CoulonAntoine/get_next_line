/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:15:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/23 09:09:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static int	ft_rest(char **rest, char **line)
// {
// 	size_t	i;
// 	char	*tmp;
	
// 	if (!rest || !*rest)
// 		return (0);
// 	i = 0;
// 	tmp = *rest;
// 	while (tmp[i] && tmp[i] != '\n')
// 		i++;
// 	*line = ft_substr(tmp, 0, i);
// 	i += (tmp[i] == '\n') ? 1 : 0;
// 	*rest = ft_substr(tmp, i, ft_strlen(tmp));
// 	free(tmp);
// 	if (ft_strlen(*rest) == 0)
// 		free(*rest);
// 	return (ft_strlen(*rest) > 0);
// }



// static int	ft_buffer(char bf[BUFFER_SIZE], long off, char **line, char **rest)
// {
	
// }

// int			get_next_line(int fd, char **line)
// {
// 	static char	*fd_rest[OPEN_MAX];
// 	char	buffer[BUFFER_SIZE + 1];
// 	long	offset;
// 	char	*tmp;

// 	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buffer, 0))
// 		    return (-1);
// 	if ((offset = read(fd, buffer, BUFFER_SIZE)) == -1)
// 		return (RET_ERR);
// 	if (!offset)
// 	{
// 		free(fd_rest[fd]);
// 		*line = NULL;
// 		return (RET_EOF);
// 	}
// 	buffer[offset] = '\0';
// 	if (!ft_rest(&(fd_rest[fd]), line))
// 		ft_buffer(buffer, offset, line, &(fd_rest[fd]));
// 	else
// 	{
// 		tmp = &(fd_rest[fd]);
// 		fd_rest[fd] = ft_strjoin(tmp, (char *)buffer);
// 		free(tmp);
// 	}
// 	return (RET_RED);
// }


static int	ft_rest(char **rest, char **line)
{
	size_t	i;
	char	*tmp;
	
	if (!rest || !*rest)
		return (0);
	i = 0;
	tmp = *rest;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*line = ft_substr(tmp, 0, i);
	if (ft_strlen(tmp) > i)
	{
		i++;
		*rest = ft_substr(tmp, i, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

static int	ft_read(int fd, char **rest, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp1;
	char	*tmp2;
	int		offset;
	int		i;

	if (!(offset = read(fd, buffer, BUFFER_SIZE)) || offset == -1)
		return (offset);
	buffer[offset] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp1 = *line;
	if (!(tmp2 = ft_substr((char *)buffer, 0, i)))
		return (RET_ERR);
	if (!(*line = ft_strjoin(*line, tmp2)))
		return (RET_ERR);
	
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_rest[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, 0, 0))
		    return (-1);
	if (!ft_rest(&(fd_rest[fd]), line))
		return (ft_read(fd, &(fd_rest[fd]), line));
	return (1);
}