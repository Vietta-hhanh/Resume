#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		ft_loop(char **line, char **remain, int writtenbytes, int fd)
{
	char		*ptrfree;
	char		*ptrz;
	char		buffer[BUFFER_SIZE + 1];

	ptrz = 0;
	while (ptrz == 0 && writtenbytes)
	{
		if ((writtenbytes = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (-1);
		buffer[writtenbytes] = 0;
		if ((ptrz = ft_strchr(buffer, '\n')))
		{
			*ptrz = 0;
			if ((*remain = ft_strdup(++ptrz)) == NULL)
				return (-1);
		}
		ptrfree = *line;
		if ((*line = ft_strjoin(*line, buffer)) == NULL)
			return (-1);
		if (ptrfree)
			free(ptrfree);
	}
	if (writtenbytes == 0)
		return (0);
	return (1);
}

char	*ft_check(char **remain, char **line)
{
	char		*ptrz;
	char		*ptrfree;

	if ((ptrz = ft_strchr(*remain, '\n')))
	{
		*ptrz = 0;
		ptrfree = *remain;
		if (!(*line = ft_strdup(*remain)))
			return (0);
		++ptrz;
		if (!(*remain = ft_strdup(ptrz)))
			return (0);
		if (ptrfree)
			free(ptrfree);
		return (*line);
	}
	if (!(*line = ft_strdup(*remain)))
		return (0);
	free(*remain);
	*remain = 0;
	return (*line);
}

int		get_next_line(int fd, char **line)
{
	static char	*remain;
	int			writtenbytes;
	int			k;

	if (fd < 0 || line == 0)
		return (-1);
	k = 1;
	writtenbytes = 1;
	*line = 0;
	if (remain)
		if (!(*line = ft_check(&remain, line)))
			return (-1);
	if (remain == 0)
		k = ft_loop(line, &remain, writtenbytes, fd);
	return (k);
}
