#include "libft.h"

char					*ft_substr(char const *s,
unsigned int start, size_t len)
{
	char				*d;
	unsigned int		i;
	size_t				buf;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		++i;
	buf = len;
	if (start >= i)
		buf = 0;
	i = 0;
	d = (char *)malloc((int)buf * sizeof(char) + 1);
	if (NULL == d)
		return (NULL);
	while (i < (unsigned int)buf)
	{
		d[i] = s[start + i];
		++i;
	}
	d[i] = '\0';
	return (d);
}
