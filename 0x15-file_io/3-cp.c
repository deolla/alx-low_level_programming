#include "main.h"

/**
 * main - start of function.
 * @argc: int argument/parameter.
 * @argv: char argument/parameter.
 *
 * Return: int.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUF_SIZE], *file_from = argv[1], *file_to = argv[2];
	ssize_t read_size, write_size;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	while ((read_size = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_size = write(fd_to, buffer, read_size);
		if (write_size != read_size)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (read_size == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
