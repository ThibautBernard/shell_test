#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list_s
{
    char *str;
    struct list_s *next;
} list_t;
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
list_t *add_nodechar_end(list_t **head, char *s)
{
	list_t *next;

	next = malloc(sizeof(list_t));
	if (next == NULL)
		return (NULL);
	if (next != NULL)
	{
		next->str = s;
		next->next = NULL;
		if (*head == NULL)
			*head = next;
		else
		{
			list_t *tmp = *head;

			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = next;
		}
	}
	return (next);
}

int main(void)
{
	list_t *head = NULL;
	char *path, *tmp, *tmp2;
	int i = 0, y = 0;
	path = _getenv("PATH");
	tmp = strtok(path, "/");
	while (tmp != NULL)
	{
		add_nodechar_end(&head, tmp);
		tmp = strtok(NULL, "/");
		i++;
	}
	while (head != NULL)
	{
			printf("%s\n", head->str);
			head = head->next;
	}
}
