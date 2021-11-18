#!/usr/bin/python3
"""0-island_perimeter.py
"""


def island_perimeter(grid):
    """island_perimeter:
        args: grid
        return: perimeter of the island described in grid
    """
    islandPerimeter = 0
    len_x = len(grid[0])
    len_y = len(grid)

    for i in range(len_y):
        for j in range(len_x):
            if not (grid[i][j] - 1):
                islandPerimeter = islandPerimeter + 4
                if (i > 0 and not (grid[i - 1][j] - 1)):
                    islandPerimeter = islandPerimeter - 2
                if (j > 0 and not (grid[i][j - 1] - 1)):
                    islandPerimeter = islandPerimeter - 2

    return islandPerimeter
