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

int main(void)
{
	int i = 0;
	char *path;
	path = _getenv("PATH");
	while(path[i])
	{
		putchar(path[i]);
		if (path[i] == '/' && i > 0 || path[i + 1] == '\0')
		{
			putchar('\n');;
		}
		i++;

	}
}
