#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
		++j;
	while (s[j - i] != (char)c && i < j)
		++i;
	if (s[j - i] == (char)c)
		return (&(((char*)s)[j - i]));
	return (0);
}
