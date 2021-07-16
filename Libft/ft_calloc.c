#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = (void *)malloc(count * size);
	if (!p)
		return (0);
	i = 0;
	while (i < (int)count * (int)size)
		((char *)p)[i++] = '\0';
	return (p);
}
