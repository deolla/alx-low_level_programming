#include "main.h"

/**
 * _strlen_recursion - a function that returns the length of a string.
 * @s: string
 *
 * Description: returns the length of a string.
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen_recursion(s + 1));
	}
}
/**
 * comparator - compares strings.
 * @s: string
 * @m: smallest iterator
 * @n: largest iterator
 *
 * Description: comparing strings
 * Return: value
 */

int comparator(char *s, int m, int n)
{
	if (*(s + m) == *(s + n))
	{
		if (m == n || m == n + 1)
			return (1);
		return (0 + comparator(s, m + 1, n - 1));
	}
	return (0);
}

/**
 * is_palindrome - a palindrome string.
 * @s: string.
 *
 * Description: detest if a string is a palindrome.
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (comparator(s, 0, _strlen_recursion(s) - 1));
}
