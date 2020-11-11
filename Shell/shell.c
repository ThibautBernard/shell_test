#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main (void)
{
	pid_t child_pid;
	char *line;
  char *argv[100];
	char *test;
	size_t len = 1;
	ssize_t read = 0;
	int i = 0, status;
	printf("$");
	read = getline(&line, &len, stdin);
	test = line;
	printf("%s", line);
 	/**if (execve(argv[0], argv, NULL) == -1)
		{
       perror("Error:");
		}*/
	/*
		child_pid = fork();
		if (child_pid == -1)
		{
    	perror("Error:");
    	return (1);
  	}
		if (child_pid == 0)
		{
			//printf("Wait for me, wait for me, %d %d \n", getpid(), getppid());
		}
		else
		{
			wait(&status);
      //printf("Oh, it's all better now %d\n", getpid());
      //printf("Hello from Parent! %d \n", getppid()); 
		}
	*/
	return (0);

}
