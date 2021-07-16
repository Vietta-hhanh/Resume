#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while ((int)n > i)
	{
		++i;
		((char*)dst)[n - i] = ((char*)src)[n - i];
	}
	return (dst);
}
