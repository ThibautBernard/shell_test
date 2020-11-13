#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
char *varEnv(const char *name, const char *value)
{
	char *new_var;
	int  var_len;
  struct stat sb;

	var_len = strlen(name) + strlen(value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (!new_var)
	{
		return (NULL);
	}
	new_var = strcat(new_var, name);
	new_var = strcat(new_var, "/");
	new_var = strcat(new_var, value);

	return (new_var);
}
int main(int ac, char **av, char **env)
{
	char *str, *ret; const char*s;
           struct stat sb;

	int i;
	str = getenv("PATH");
	printf("%s\n", str);	
	s = strtok(str, ":");
	while (s)
	{
		ret = varEnv(s, "ls");
		i = stat(ret, &sb);
		if (i == 0)
		{
			printf("->%s\n", ret);
			break;
		}
		printf("%s\n", ret);
		s = strtok(NULL, ":");
	}


	return (0); 
}
