#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	int		i;
	size_t	buf;

	i = 0;
	buf = len;
	while ((int)buf > 0)
	{
		((char *)b)[i++] = (unsigned char)c;
		--buf;
	}
	return (b);
}
