#include "get_next_line.h"

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

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return ((size_t)i);
}

char		*ft_strjoinhelp(char const *s2)
{
	int		i;
	char	*s;

	i = ft_strlen(s2);
	if ((s = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s[i] = s2[i];
		++i;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strjoinhelp(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
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
