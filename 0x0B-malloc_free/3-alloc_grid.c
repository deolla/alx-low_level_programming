#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of an array.
 * @height: height of an array.
 *
 * Description: a function that returns a pointer
 * to a 2 dimensional array of integers.
 * Return: pointer.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int m, n;

	if (width < 1 || height < 1)
	{
		return (NULL);
	}
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (m = 0; m < height; m++)
	{
		grid[m] = malloc(width * sizeof(int));
		if (grid[m] == NULL)
		{
			for (m--; m >= 0; m--)
				free(grid[m]);
			free(grid);
			return (NULL);
		}
	}

	for (m = 0; m < height; m++)
		for (n = 0; n < width; n++)
			grid[m][n] = 0;

	return (grid);
}
