#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char buf[BUFSIZ];
	static char *ptr;
	static int n;

	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof buf);
		ptr = buf;
	}
	if (--n >= 0)
		return (unsigned char)*ptr++;
	else
		return EOF;
}
