#include "libft.h"

int		ft_atoi(const char *str)
{
	int k;
	int rez;
	int i;

	k = 1;
	i = 0;
	rez = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		++i;
	if (str[i] == 45)
		k = -1;
	if (str[i] == 45 || str[i] == 43)
		++i;
	while (str[i] >= 48 && str[i] <= 57)
		rez = rez * 10 + str[i++] - '0';
	return (rez * k);
}
