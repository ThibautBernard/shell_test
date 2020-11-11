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
		size_t len = 1;
		int status;
		while(len)
		{
			printf("#cisfun$ ");
			child_pid = fork();
			if (child_pid == -1)
			{
    		perror("Error:");
    		return (1);
  		}
			if (child_pid == 0)
			{
				re = getline(&buffer, &len, stdin);
        char *args[64];
        char **next = args;
        char *temp = strtok(buffer, " \n");
        while (temp != NULL)
        {
           *next++ = temp;
           temp = strtok(NULL, " \n");
        }
        *next = NULL;
		//		printf("Enfant, process en cours : %d\n", getpid());
        execve(args[0], args, NULL);
			}
			else
			{
				wait(&status);
//     	printf("Hello from Parent! %d \n", getpid());
	//		printf("Big parent pid : %d\n", getppid());
			}
		}
    return (0);
}
