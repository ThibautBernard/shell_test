#include <stdio.h>
int main(int ac, char**av, char **env)
{
	int i;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
