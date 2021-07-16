#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*buf;

	buf = (char *)s;
	while (*buf != (char)c && *buf)
		++buf;
	if ('\0' == c)
		return (buf);
	if (*buf)
		return (buf);
	return (0);
}
