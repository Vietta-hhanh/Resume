#include "./../heade.h"

void	ft_converterv2(unsigned long int dec, int degree, char *result)
{
	while ((degree) >= 0)
	{
		if (dec % 16 == 10)
			result[degree--] = 'a';
		else if (dec % 16 == 11)
			result[degree--] = 'b';
		else if (dec % 16 == 12)
			result[degree--] = 'c';
		else if (dec % 16 == 13)
			result[degree--] = 'd';
		else if (dec % 16 == 14)
			result[degree--] = 'e';
		else if (dec % 16 == 15)
			result[degree--] = 'f';
		else
			result[degree--] = '0' + dec % 16;
		dec = dec / 16;
	}
}

char	*ft_converter(unsigned long int dec)
{
	char				*result;
	unsigned long int	buf;
	int					degree;

	degree = 1;
	buf = dec;
	while (buf > 16)
	{
		buf /= 16;
		++degree;
	}
	if ((result = malloc(degree + 1)) == 0)
		return (0);
	result[degree--] = 0;
	ft_converterv2(dec, degree, result);
	return (result);
}
