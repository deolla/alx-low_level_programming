#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes.
 * @argc: Argument count.
 * @argv: Argument pointer.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *opp = (char *) main;
	int m, mybyt;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	mybyt = atoi(argv[1]);

	if (mybyt < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (m = 0; m < mybyt; m++)
	{
		printf("%02x", opp[m] & 0xFF);
		if (m != mybyt - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
