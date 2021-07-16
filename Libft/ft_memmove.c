#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 1;
	if (src < dst)
	{
		while ((int)len >= i)
		{
			((unsigned char *)dst)[len - i] = ((unsigned char *)src)[len - i];
			++i;
		}
	}
	else
	{
		while ((int)len >= i)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			++i;
		}
	}
	return (dst);
}
