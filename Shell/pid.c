#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid_parent, my_pid_child;

    my_pid_parent = getppid();
		my_pid_child = getpid();
    printf("parent : %u\n child %u\n", my_pid_parent, my_pid_child);
    return (0);
}
