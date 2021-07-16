#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		++i;
	if ((result = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, (char)s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}
