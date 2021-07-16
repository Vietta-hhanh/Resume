#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*by;
	size_t			buf;

	by = (unsigned char *)s;
	i = 0;
	buf = n;
	while ((int)buf-- > 0)
	{
		if (by[i] == (unsigned char)c)
			return ((void *)(by + i));
		++i;
	}
	return (NULL);
}
