#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int ac, char **av, char **env) 
{
	pid_t child_pid;
	int re, i = 0;
	char *buffer = NULL;
	size_t len = 0;
	int status;
	char delimiters[] = " \t\r\n\v\f";
	char *argv[10];
	char *temp;
	printf("$ ");
	while(1)
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
			temp = strtok(buffer, delimiters);
			while(temp)
			{
				argv[i] = temp;
				temp = strtok(NULL, delimiters);
				i++;
			}
			argv[i] = NULL;
			execve(argv[0], argv, env);
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
