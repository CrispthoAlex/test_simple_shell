#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - read line
 *
 * Return: Always 0 success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;/*chars read by getline() */
	char *tokens = NULL;/* containt each string typing */
	/*char *limstr[] = {" ", "\t", "\0", "\\-r"}; string delimited */
	char *argstr[100];/* arguments input*/
	int i = 0;
	int exe_child;/*value return by execve*/
	int status;/*status return*/


	/*number of characters written into the buffer*/
	/*read = getline(&line, &len, fp);*/
	while (1)
	{
		printf("#cisfun$> ");/*prompt */

		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		tokens = strtok(line, " \t\n\r");

		i = 0;
		while (tokens != NULL)/*token each string*/
		{
			argstr[i] = tokens;
			if(!strcmp("exit", argstr[0]))
				exit(1);
			tokens = strtok(NULL, " \t\n\r");
			i++;
		}
		argstr[i] = NULL;

		/*// SEARCHING PATH PHASE \\ */
			/*-----------------*/

		/*// EXECUTE PHASE \\ */

		exe_child = fork();
		if (exe_child == 0)
		{
			if (execve(argstr[0], argstr, NULL) == -1)
			{
				perror("Do not execute the command");
				exit(1);
			}
		}
		else
			wait(&status);
	}
	free(line);
	return (0);
}
