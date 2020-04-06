#include <stdio.h>
#include <unistd.h>

/**
 * main - prints all arguments
 * @argv: arguments input
 * @countarg: quantity of arguments input
 */
int main(int countarg, char **argv)
{
	int i = 0;
	pid_t mypid;
	pid_t myppid;

	mypid = getpid();
	myppid = getppid();

	if (argv)
	{
		while(argv[i] != '\0' && i < countarg)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
			i++;
		}
		printf("Prints %d arguments\nPID = %u\nPPID = %u\n", i++, mypid, myppid);
		return (0);
	}
	return (-1);
}
