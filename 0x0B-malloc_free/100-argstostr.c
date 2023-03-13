#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments.
 * @ac: an argument.
 * @av: an argument.
 *
 * Return: return pointer.
 */
char *argstostr(int ac, char **av)
{
	int m, n, o, po;
	char *sto;

	if (ac == 0)
		return (NULL);

	for (m = n = 0; n < ac; n++)
	{
		if (av[n] == NULL)
			return (NULL);

		for (o = 0; av[n][o] != '\0'; o++)
			m++;
		m++;
	}
	sto = malloc((m + 1) * sizeof(char));

	if (sto == NULL)
	{
		free(sto);
		return (NULL);
	}

	for (n = o = po = 0; po < m; o++, po++)
	{
		if (av[n][o] == '\0')
		{
			sto[po] = '\n';
			n++;
			po++;
			o = 0;
		}
		if (po < m - 1)
			sto[po] = av[n][o];
	}
	sto[po] = '\0';
	return (sto);
}
