/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:12:08 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/23 08:20:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 32
# define RET_RED 1
# define RET_EOF 0
# define RET_ERR -1

/*
** ***** GNL    ************************************************************* **
*/

int		get_next_line(int fd, char **line);

/*
** ***** UTILS    *********************************************************** **
*/

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, const char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
