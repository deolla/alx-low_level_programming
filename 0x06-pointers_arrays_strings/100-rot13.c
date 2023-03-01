#include "main.h"

/**
 * rot13 - a function that encodes a string.
 * @str: the string to be encode.
 *
 * Return: the encoded string.
 */
char *rot13(char *str)
{
	int a, b;
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	a = 0;
	while (str[a] != '\0')
	{
		b = 0;
		while (upper[b] != '\0')
		{
			if (str[a] == upper[b])
			{
				str[a] = rot[b];
				break;
			}
			b++;
		}
		a++;
	}
	return (str);
}
