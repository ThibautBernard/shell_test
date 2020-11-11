#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *_getenv(const char *name)
{
	int i = 0, y = 0;
	char *tmp, *tmp2;
	extern char **environ;
	if (name == NULL)
		return (NULL);
	while (environ[i])
	{
		tmp = strtok(environ[i], "=");
		if (strcmp(name, tmp) == 0)
		{
			while(y < 1)
			{
				tmp2 = tmp;
				tmp = strtok(NULL, "=");
				y++;
			}
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
	extern char **environ;
	int i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}	
	const char *n = "USER";
	char *tot = _getenv(n);
	printf("user : ->%s\n", tot);
	char *x = _getenv("PATH");
	printf("path : %s\n", x);
	char *t = _getenv("USER");
	printf("Home : %s\n", t);

}
