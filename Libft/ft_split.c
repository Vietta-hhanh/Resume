#include "libft.h"

static short int		ft_size(char const *str, char c)
{
	short int			border;
	int					count;
	char				*s;
	int					i;

	i = 0;
	s = (char *)str;
	border = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && border == 0)
		{
			border = 1;
			++count;
		}
		if (s[i] == c && border == 1)
			border = 0;
		++i;
	}
	return (count);
}

static int				ft_wordsize(char *s, char c)
{
	int					i;
	char				*buf;

	buf = s;
	i = 0;
	while (*buf == c && *buf)
		++buf;
	while (*buf != c && *buf)
	{
		++i;
		++buf;
	}
	return (i);
}

static char				*ft_fill(char *dst, char *s, char c)
{
	int					j;

	j = 0;
	while (*s == c && *s)
		++s;
	while (*s != c && *s)
		dst[j++] = *(s++);
	dst[j] = '\0';
	return (s);
}

static void				ft_clean(char **d, int i)
{
	while (i >= 0)
		free(d[i--]);
	free(d);
}

char					**ft_split(char const *s, char c)
{
	char				**d;
	char				*buf;
	int					count;
	int					i;

	if (s == NULL)
		return (NULL);
	buf = (char *)s;
	i = 0;
	count = ft_size(s, c);
	if ((d = (char **)malloc(sizeof(char *) * count + 1)) == NULL)
		return (NULL);
	while (count > i)
	{
		if (!(d[i] = (char *)malloc(sizeof(char) * ft_wordsize(buf, c) + 1)))
		{
			ft_clean(d, i);
			return (NULL);
		}
		buf = ft_fill(d[i], buf, c);
		++i;
	}
	d[i] = NULL;
	return (d);
}
