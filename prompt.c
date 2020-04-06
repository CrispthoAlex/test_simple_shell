#include <stdio.h>
#include <stdlib.h>
/**
 * main - read line
 *
 * Return: Always 0 success
 */
int main(void)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	/*str_catch find how catch the input;*/
	fp = fopen("./print_av.c", "r");
	if (fp == NULL)
		exit(1);

	/*number of characters written into the buffer*/
	/*read = getline(&line, &len, fp);*/
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Retrieved line of length %lu :\n", (unsigned long)read);
		printf("%s", line);
	}
	if (ferror(fp))
		printf("Not file exist, try again");/* handle error */
	free(line);
	fclose(fp);
	return (0);
}
