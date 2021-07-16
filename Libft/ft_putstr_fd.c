#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int bytestowrite;

	if (s == NULL)
		return ;
	bytestowrite = 0;
	while (s[bytestowrite])
		++bytestowrite;
	write(fd, s, bytestowrite * sizeof(char));
}
