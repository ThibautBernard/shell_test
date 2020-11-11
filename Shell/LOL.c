#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (void)
{
	int y = 0;
	char *line = NULL;
	char *tmp;
	char delim[2] = " ";
  size_t len = 1;
	size_t of = 0;
	int re = 0;
	char **argv;
	while (len)
	{
		printf("$");
		re = getline(&line, &len, stdin);
		tmp = strtok(line, delim);
		char *test[] = {tmp, NULL};
		//argv = malloc(sizeof(char*)*len);
		/*for (int i = 0; i < 1; i++)
		{
			argv[i] = malloc(sizeof(char)*re);
			for ( y = 0; y < re; y++)
			{
				argv[i][y] = line[y];
			}
		}
		*/
		if (execvp(test[0], test) == -1)
		{
       perror("Error:");
		}
	}
	return (0);
}
