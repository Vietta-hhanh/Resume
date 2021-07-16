#include "libft.h"

static void			ft_out(int fd, int result)
{
	char			a;

	a = '0' + result;
	write(fd, &a, sizeof(char));
}

static long int		ft_minus(long int bbuf, int fd)
{
	if (bbuf < 0)
	{
		ft_out(fd, -3);
		bbuf = -bbuf;
	}
	return (bbuf);
}

void				ft_putnbr_fd(int n, int fd)
{
	long int		buf;
	long int		bbuf;
	int				i;
	int				j;

	i = 0;
	bbuf = ft_minus(n, fd);
	buf = bbuf;
	while (buf / 10 != 0)
	{
		buf = buf / 10;
		++i;
	}
	buf = bbuf;
	while (i >= 0)
	{
		j = i--;
		buf = bbuf;
		while (j-- > 0)
			buf = buf / 10;
		buf = buf % 10;
		ft_out(fd, buf);
	}
}
