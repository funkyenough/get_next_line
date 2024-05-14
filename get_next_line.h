/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:32:48 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/14 11:34:06 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_line
{
	char	*ret;
	size_t	len;
	size_t	cap;
}			t_line;

char		*get_next_line(int fd);
int			ft_getc(int fd);
void		ft_putc(t_line *line, char c);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif