/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:12:08 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/21 11:00:08 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 32

/*
** ==== GNL    =================================================================
*/

int		get_next_line(int fd, char **line);

/*
** ==== UTILS ==================================================================
*/

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len)


#endif
