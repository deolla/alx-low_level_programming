#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX.
 * @filename: file name.
 * @letters: the number of letters.
 *
 * Return: number of letters.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ppp ;
	ssize_t pop_r, pop_w;
	FILE *fp;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (0);
	}

	ppp = malloc(sizeof(char) * letters);
	if (ppp == NULL)
	{
		fclose(fp);
		return (0);
	}

	pop_r = fread(ppp, sizeof(char), letters, fp);
	if (pop_r == 0)
	{
		fclose(fp);
		free(ppp);
		return (0);
	}

	pop_w = write(STDOUT_FILENO, ppp, pop_r);
	if (pop_w != pop_r)
	{
		fclose(fp);
		free(ppp);
		return (0);
	}

	fclose(fp);
	free(ppp);
	return (pop_w);

}
