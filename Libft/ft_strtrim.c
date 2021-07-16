#include "libft.h"

static int	ft_frontborder(char const *s1, char const *set)
{
	char	*s;
	char	*c;
	int		i;
	int		j;
	int		border;

	j = 0;
	i = 0;
	c = (char *)set;
	s = (char *)s1;
	border = 1;
	while (s[j] && border)
	{
		i = 0;
		border = 0;
		while (c[i])
		{
			if (c[i] == s[j])
				border = 1;
			++i;
		}
		if (border == 1)
			++j;
	}
	return (j);
}

static int	ft_backborder(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		length;
	int		border;

	s = (char *)s1;
	length = 0;
	while (s[length + 1])
		++length;
	border = 1;
	while (length >= 0 && border == 1)
	{
		i = 0;
		border = 0;
		while (set[i])
		{
			if (s[length] == ((char *)set)[i])
				border = 1;
			++i;
		}
		if (border == 1)
			--length;
	}
	return (length);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_frontborder(s1, set);
	k = ft_backborder(s1, set);
	if (j > k)
	{
		if ((d = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
	}
	else if ((d = (char *)malloc((k - j + 2) * sizeof(char))) == NULL)
		return (NULL);
	while (i < k - j + 1 && j <= k)
	{
		d[i] = ((char *)s1)[j + i];
		++i;
	}
	d[i] = 0;
	return (d);
}
