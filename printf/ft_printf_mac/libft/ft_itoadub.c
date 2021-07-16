#include "./../heade.h"

char			*ft_filldub(char *result, int i, unsigned int n)
{
	unsigned int	buf;

	buf = n;
	result[i + 1] = '\0';
	while (i != 0)
	{
		result[i--] = buf % 10 + '0';
		buf = buf / 10;
	}
	result[i] = buf + '0';
	return (result);
}

char			*ft_dub(unsigned int n)
{
	unsigned int	buf;
	char			*result;
	int				i;

	i = 0;
	buf = n;
	while (buf / 10 != 0)
	{
		buf = buf / 10;
		++i;
	}
	if ((result = (char *)malloc(sizeof(char) * (i + 1) + 1)) == NULL)
		return (NULL);
	return (ft_filldub(result, i, n));
}
