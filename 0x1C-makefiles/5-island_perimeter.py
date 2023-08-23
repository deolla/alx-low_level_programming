#!/usr/bin/python3
"""
returns the perimeter of the island described in grid
"""
def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    Returns:
        The perimeter of the island.
    """
    perimeter = 0

    for row in range(len(grid)):
        for column in range(len(grid[0])):
            if grid[row][column] == 1:
                perimeter += 4
                if row > 0 and grid[row -1][column] == 1:
                    perimeter -= 2
                if column > 0 and grid[row][column - 1] == 1:
                    perimeter -= 2

    return perimeter


