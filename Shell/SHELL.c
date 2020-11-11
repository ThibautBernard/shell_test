#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void) 
{
	pid_t child_pid;
	int re;
	char *buffer;
	size_t len = BUFFSIZE;
	int status;
	char **argv;
	char *temp;
	char *s;
	int length_arg = 0, i = 0, b = 0;
	printf("$ ");
	while(b == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
    	perror("Error:");
    	return (1);
  	}
		if (child_pid == 0)
		{
			re = getline(&buffer, &len, stdin);
			temp = strtok(buffer, " \n");
			argv = malloc(sizeof(char*)*re);
			while(temp)
			{
				argv[i] = temp;
				temp = strtok(NULL, " \n");
				i++;
			}
			argv[i] = NULL;
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
		b++;
	}
	return (0);
}
