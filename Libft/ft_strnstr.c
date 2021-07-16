#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int k;

	i = 0;
	while (needle[i])
		++i;
	if (i == 0)
		return ((char*)haystack);
	k = 0;
	j = 0;
	while (needle[k] && haystack[j] && j <= (int)len - i)
	{
		while (needle[k] == haystack[k + j] && needle[k])
			++k;
		if (k == i)
			return (&((char*)haystack)[j]);
		j++;
		k = 0;
	}
	return (0);
}
