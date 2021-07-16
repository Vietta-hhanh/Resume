#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		++i;
	while (s2[j])
		++j;
	if ((s = (char *)malloc(sizeof(char) * (j + i) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		++i;
	}
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
