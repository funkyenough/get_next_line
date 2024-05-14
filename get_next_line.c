/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:39:08 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/14 11:45:14 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	c;
	t_line	line;

	if (fd < 0)
		return (NULL);
	line.ret = NULL;
	line.len = 0;
	line.cap = 1;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		ft_putc(&line, c);
		if (c == '\n')
			break ;
	}
	if (line.len > 0)
		ft_putc(&line, '\0');
	return (line.ret);
}

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*ptr;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof buf);
		ptr = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*ptr++);
	else
		return (EOF);
}

void	ft_putc(t_line *line, char c)
{
	char	*new_line;

	if (line->len + 1 >= line->cap)
	{
		line->cap *= 2;
		new_line = (char *)malloc(sizeof(char) * line->cap);
		if (new_line == NULL)
			return ;
		ft_memcpy(new_line, line->ret, line->len);
		free(line->ret);
		line->ret = new_line;
	}
	line->ret[line->len] = c;
	line->len++;
}

// int	main(void)
// {
// 	char	fileName[] = "./test.txt";
// 	int		fd;

// 	fd = open(fileName, 2);
// 	if (fd == -1)
// 	{
// 		printf("\nError Opening File!!\n");
// 		exit(1);
// 	}
// 	else
// 	{
// 		printf("\n%d Bytes from File %s opened sucessfully!\n", fd, fileName);
// 	}
// 	for (int i = 0; i < 3; i++)
// 		printf("%s", get_next_line(fd));
// 	return (0);
// }
