#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;/*PID*/

	my_pid = getpid();
	printf("This is PID: %u\n", my_pid);

	pid_t my_ppid;/*PPID*/

	my_ppid = getppid();
	printf("This is PPID: %u\n", my_ppid);
	return (0);
}
