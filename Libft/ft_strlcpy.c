#include "libft.h"

size_t	ft_strlcpy(char *restrict dst,
const char *restrict src, size_t dstsize)
{
	int i;
	int j;

	if (dst == NULL || src == NULL)
		return (0);
	j = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	i = 0;
	while ((int)dstsize - 1 > i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
