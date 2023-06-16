#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * findLargestNum - Finds the largest number in a given username.
 * @tag: The username
 * @lenght: Length of the username
 *
 * Return: largest number
 */
int findLargestNum(char *tag, int lenght)
{
	int pop, lol;
	unsigned int rand_num;

	pop = *tag;
	lol = 0;

	while (lol < lenght)
	{
		if (pop < tag[lol])
			pop = tag[lol];
		lol += 1;
	}

	srand(pop ^ 14);
	rand_num = rand();

	return (rand_num & 63);
}

/**
 * multiplyUsername - Multiplies each character of username.
 * @tag: The username
 * @lenght: Length of the username
 *
 * Return: Multiplied character.
 */
int multiplyUsername(char *tag, int lenght)
{
	int pop, lol;

	pop = lol = 0;

	while (lol < lenght)
	{
		pop = pop + tag[lol] * tag[lol];
		lol += 1;
	}

	return (((unsigned int)pop ^ 239) & 63);
}

/**
 * generateRandomChar - Generates a random character.
 * @tag: The username.
 *
 * Return: A random character.
 */
int generateRandomChar(char *tag)
{
	int pop, lol;

	pop = lol = 0;

	while (lol < *tag)
	{
		pop = rand();
		lol += 1;
	}

	return (((unsigned int)pop ^ 229) & 63);
}

/**
 * main - Start of function
 * @argc: Int arguments count
 * @argv: Char double pointer arguments vector
 *
 * Return: Always 0 (success).
 */
int main(int argc, char **argv)
{
	char key[7];
	int lenght, pop, lol;
	long binary[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	for (lenght = 0; argv[1][lenght]; lenght++)
		;
	/* ----------- first part ----------- */
	key[0] = ((char *)binary)[(lenght ^ 59) & 63];
	/* ----------- second part ----------- */
	pop = lol = 0;
	while (lol < lenght)
	{
		pop = pop + argv[1][lol];
		lol = lol + 1;
	}
	key[1] = ((char *)binary)[(pop ^ 79) & 63];
	/* ----------- thrid part ----------- */
	pop = 1;
	lol = 0;
	while (lol < lenght)
	{
		pop = argv[1][lol] * pop;
		lol = lol + 1;
	}
	key[2] = ((char *)binary)[(pop ^ 85) & 63];
	/* ----------- fourth part ----------- */
	key[3] = ((char *)binary)[findLargestNum(argv[1], lenght)];
	/* ----------- fifth part ----------- */
	key[4] = ((char *)binary)[multiplyUsername(argv[1], lenght)];
	/* ----------- sixth part ----------- */
	key[5] = ((char *)binary)[generateRandomChar(argv[1])];
	key[6] = '\0';
	for (pop = 0; key[pop]; pop++)
		printf("%c", key[pop]);
	return (0);
}
