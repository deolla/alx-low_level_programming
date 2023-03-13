#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid.
 * @grid: dimensional grid.
 * @height: height of the grid.
 *
 * Description: a function that frees a 2 dimensional grid.
 * Return: height of the grid.
 */
void free_grid(int **grid, int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(grid[height]);
		free(grid);
	}
}
