#include "libft.h"

void		*ft_memccpy(void *restrict dst,
const void *restrict src, int c, size_t n)
{
	int		i;
	size_t	buf;

	i = 0;
	buf = n;
	while ((int)buf-- > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((unsigned char *)src)[i++] == (unsigned char)c)
			return ((void *)((char *)dst + i));
	}
	return (NULL);
}
