#include "main.h"
#include <stdlib.h>

/**
 * ray_free_grid - frees a 2 dimensional array.
 * @grid: dimensional char.
 * @height: height of the array
 *
 * Return: no return
 */
void ray_free_grid(char **grid, unsigned int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height > 0; height--)
			free(grid[height]);
		free(grid);
	}
}

/**
 * strtow - splits a string into words.
 * @str: a string.
 *
 * Description: a function that splits a string into words.
 * Return: NULL if str == NULL or str.
 */
char **strtow(char *str)
{
	char **sto;
	unsigned int a, height, m, tired, sigh;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (a = height = 0; str[a] != '\0'; a++)
		if (str[a] != ' ' && (str[a + 1] == ' ' || str[a + 1] == '\0'))
			height++;
	sto = malloc((height + 1) * sizeof(char *));
	if (sto == NULL || height == 0)
	{
		free(sto);
		return (NULL);
	}
	for (m = sigh = 0; m < height; m++)
	{
		for (a = sigh; str[a] != '\0'; a++)
		{
			if (str[a] == ' ')
				sigh++;
			if (str[a] != ' ' && (str[a + 1] == ' ' || str[a + 1] == '\0'))
			{
				sto[m] = malloc((a - sigh + 2) * sizeof(char));

				if (sto[m] == NULL)
				{
					ray_free_grid(sto, m);

					return (NULL);
				}
				break;
			}
		}
		for (tired = 0; sigh <= a; sigh++, tired++)
			sto[m][tired] = str[sigh];
		sto[m][tired] = '\0';
	}
	sto[m] = NULL;
	return (sto);
}
