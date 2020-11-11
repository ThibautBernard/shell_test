#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (void)
{
	pid_t child_pid;

	int i = 0, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
    	perror("Error:");
    	return (1);
  	}
		if (child_pid == 0)
		{
			printf("Wait for me, wait for me, %d %d \n", getpid(), getppid());
			if (execve(argv[0], argv, NULL) == -1)
   		{
       	 perror("Error:");
   		}
		}
		else
		{		
			wait(&status);
      printf("Oh, it's all better now %d\n", getpid());
      printf("Hello from Parent! %d \n", getppid()); 
		}
		i++;
	}

}
