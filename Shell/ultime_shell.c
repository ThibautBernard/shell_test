#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void _prompt()
{
  extern char **environ;

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

char **parsing(char *buffer, int len)
{
	char delimiters[] = " \t\r\n\v\f";
	char *temp, **av;
	temp = strtok(buffer, delimiters);
	av = malloc(sizeof(char)*len);
	if (av == NULL)
		return (NULL);
	fill_args_toargv(temp, av, delimiters);
	return (av);
}
int main(int ac, char **av) 
{
	pid_t child_pid;
	int nb, i = 0, status;
	char *buffer = NULL, **argv;
	size_t len = 0;
	_prompt();
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
			nb = getline(&buffer, &len, stdin);
			argv = parsing(buffer, len);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(av[0]);
				free(argv);
				free(buffer);
				break;
				exit(0);
			}
		}
		else
		{
			wait(&status);
			WEXITSTATUS(&status);
		}
	}
	free(argv);
	return (0);
}
