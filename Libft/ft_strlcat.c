#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
const char *restrict src, size_t dstsize)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (dst[j])
		j++;
	while (src[k])
		++k;
	if ((int)dstsize < j)
		return (dstsize + (size_t)k);
	if (dstsize == 0)
		return (k);
	if (k == 0)
		return (j);
	i = 0;
	while ((int)dstsize - j - i - 1 > 0 && src[i])
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[j + i] = '\0';
	return (j + k);
}
