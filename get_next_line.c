/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:15:36 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/22 07:09:46 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_retrieve_rest(char **rest, char **new)
{
	size_t	i;
	char	*tmp;
	
	if (!rest || !*rest)
		return (NULL);
	i = 0;
	tmp = *rest;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*new = ft_substr(tmp, 0, i);
	i += (tmp[i] == '\n') ? 1 : 0;
	*rest = ft_substr(tmp, i, ft_strlen(tmp));

	free(tmp);
	return (ft_strlen(*rest) > 0);
}



int			get_next_line(int fd, char **line)
{
	static char	*fd_rest[OPEN_MAX];
	char	buffer[BUFFER_SIZE];
	long	offset;
	char	*tmp;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buffer, 0))
		    return (-1);
	if (!(offset = read(fd, buffer, BUFFER_SIZE)) || offset == -1)
		return (offset);
	tmp = (ft_retrieve_rest(&(fd_rest[fd]), &tmp)) ? tmp : ft_retrieve_buffer();
}