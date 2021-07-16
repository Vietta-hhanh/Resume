#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	if ((s = (char *)malloc(1 + i * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
