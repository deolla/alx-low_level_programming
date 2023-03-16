#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}


/**
 * main - multiplies two positive numbers.
 * @argc: argument.
 * @argv: argument.
 *
 * Return: always 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *pt, *pt1;
	int len1, len2, len, m, num, dig0, dig1, *result, n = 0;

	pt = argv[1], pt1 = argv[2];
	if (argc != 3 || !is_digit(pt) || !is_digit(pt1))
		errors();
	len1 = _strlen(pt);
	len2 = _strlen(pt1);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (m = 0; m <= len1 + len2; m++)
		result[m] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		dig0 = pt[len1] - '0';
		num = 0;
		for (len2 = _strlen(pt1) - 1; len2 >= 0; len2--)
		{
			dig1 = pt1[len2] - '0';
			num += result[len1 + len2 + 1] + (dig0 * dig1);
			result[len1 + len2 + 1] = num % 10;
			num /= 10;
		}
		if (num > 0)
			result[len1 + len2 + 1] += num;
	}
	for (m = 0; m < len - 1; m++)
	{
		if (result[m])
			n = 1;
		if (n)
			_putchar(result[m] + '0');
	}
	if (!n)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
