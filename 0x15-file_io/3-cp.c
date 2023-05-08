#include "main.h"

/**
 * err_d - check for error
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector.
 *
 * Return: no return.
 */
void err_d(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code.
 * @argc: char arguments.
 * @argv: int argument.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, pop_d;
	ssize_t vss, wss;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	err_d(file_from, file_to, argv);

	vss = 1024;
	while (vss == 1024)
	{
		vss = read(file_from, buf, 1024);
		if (vss == -1)
			err_d(-1, 0, argv);
		wss = write(file_to, buf, vss);
		if (wss == -1)
			err_d(0, -1, argv);
	}

	pop_d = close(file_from);
	if (pop_d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	pop_d = close(file_to);
	if (pop_d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
