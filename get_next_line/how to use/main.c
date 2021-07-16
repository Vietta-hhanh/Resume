#include "./../get_next_line.h"
#include <stdio.h>
int main ()
{
	int filed;
	char *line;

	line = NULL;
	filed = open("randomtext", O_RDONLY);
	for (int k = 0; k < 15; k++)
	{
	printf ("{%d - returned code}", get_next_line(filed, &line));
	printf ("%s\n", line);
		free(line);
	}
	return 0;
}

