#include <stdio.h>

int main (int ac, char *av[])
{
	char *line;
  size_t len = 0;
	printf("$");
	getline(&line, &len, stdin);
	printf("%s", line);
}
