#include <stdio.h>
#include <unistd.h>
int main(int ac, char**av, char **env)
{
	int i = 0;
	extern char **environ;
	printf("Environ : \n");
		printf("%p\n", environ);
	printf("Env : \n");
		printf("%p\n", env);
	


}
