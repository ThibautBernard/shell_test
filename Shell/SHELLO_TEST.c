#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void _prompt(char **env)
{
	char *prompt;
//	setenv("PS1", ">", 0);
	if ((prompt = getenv("PS1")) == NULL)
	{
		printf("($) ");
	}
	else
		printf("%s", prompt);
}
void fill_args_toargv(char *temp, char **argv, char *delimiters)
{
	int i = 0;
	while(temp)
	{
		argv[i] = temp;
		temp = strtok(NULL, delimiters);
		i++;
	}
	argv[i] = NULL;
}
int main(int ac, char **av, char **env) 
{
	pid_t child_pid;
	int re, i = 0, status;
	char *buffer = NULL, **argv, *temp;
	size_t len = 0;
	char delimiters[] = "; \t\r\n\v\f";
	_prompt(env);
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
			argv = malloc(sizeof(char)*len);
			fill_args_toargv(temp, argv, delimiters);
			if (execve(argv[0], argv, env) == -1)
			{
				perror(av[0]);
				free(temp);
				free(argv);
				break;
			}
		}
		else
			wait(&status);
	}
//	free(buffer);
//	free(temp);
	return (0);
}
