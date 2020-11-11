#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int i = 0;
	extern char **environ;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

}
