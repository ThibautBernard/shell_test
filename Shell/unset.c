#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *varEnv(const char *name, const char *value)
{
	char *new_var;
	int  var_len;

	var_len = strlen(name) + strlen(value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (!new_var)
	{
		return (NULL);
	}
	new_var = strcat(new_var, name);
	new_var = strcat(new_var, "=");
	new_var = strcat(new_var, value);

	return (new_var);
}
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int i = 0, length_name = 0;
	length_name = strlen(name);
	while (environ[i])
	{
		if (strncmp(name, environ[i], length_name) == 0)
		{
			environ[i] = varEnv(name, value);
			return (0);
		}
		i++;
	}
	environ[i] = varEnv(name, value);
	i++;
	environ[i] = NULL;
	i = 0;
}
int _unsetenv(const char *name)
{
	extern char **environ;
	int i = 0, length_name = 0;
	length_name = strlen(name);
	while (environ[i])
	{
		if (strncmp(name, environ[i], length_name) == 0)
		{
			free(environ[i]);
			environ[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}
int main(void)
{
	extern char **environ;
	_setenv("BOBO", "haha", 0);
	_unsetenv("BOBO");
	int i = 0;
	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
