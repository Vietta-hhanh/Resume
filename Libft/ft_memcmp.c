#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	size_t	buf;

	i = 0;
	buf = n;
	while ((int)buf-- > 0)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		++i;
	}
	return (0);
}
