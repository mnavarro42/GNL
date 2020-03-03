#include "get_next_line.h"
#include <stdio.h>

int main ()
{
	char *c = (char *)malloc(sizeof(char) * 4096);
	char **m = &c;

	int fd = open("prueba", O_RDONLY);
	int n;
	while ((n = get_next_line(fd, m)) > 0)
	{
		printf("Linea: %s\n", *m);
		free(*m);
	}
	close(fd);
	return (0);
}