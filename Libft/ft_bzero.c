#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	int		i;
	size_t	buf;

	buf = n;
	i = 0;
	while ((int)buf > 0)
	{
		((char *)s)[i++] = '\0';
		--buf;
	}
}
