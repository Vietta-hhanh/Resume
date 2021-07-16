#include "./../heade.h"

char			*ft_fill(char *result, int i, int k, int n)
{
	long int	buf;

	buf = n;
	if (n < 0)
		buf = -buf;
	result[i + 1 + k] = '\0';
	while (i != 0)
	{
		result[k + i--] = buf % 10 + '0';
		buf = buf / 10;
	}
	result[i + k] = buf + '0';
	if (k)
		result[i] = '-';
	return (result);
}

char			*ft_itoa(int n)
{
	long int	buf;
	char		*result;
	int			i;
	int			k;

	i = 0;
	buf = n;
	k = 0;
	if (buf < 0)
	{
		k = 1;
		buf = -buf;
	}
	while (buf / 10 != 0)
	{
		buf = buf / 10;
		++i;
	}
	if ((result = (char *)malloc(sizeof(char) * (i + 1 + k) + 1)) == NULL)
		return (NULL);
	return (ft_fill(result, i, k, n));
}
