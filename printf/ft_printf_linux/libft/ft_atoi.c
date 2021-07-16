#include "./../heade.h"

int		ft_atoi_down(const char *str, int *index)
{
	int rez;

	rez = 0;
	while (str[*index] >= 48 && str[*index] <= 57)
		rez = rez * 10 + str[(*index)++] - '0';
	--(*index);
	return (rez);
}
