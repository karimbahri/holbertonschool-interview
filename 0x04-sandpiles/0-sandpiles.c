#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - compute the sum of two grids
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid[3][3];
	int i = 0, j = 0;

	if (!grid1 || !grid2)
		return;

	for (i = 0 ; i < SIZE_GRID ; i++)
		for (j = 0 ; j < SIZE_GRID ; j++)
			grid1[i][j] += grid2[i][j];

	while (!check_stable(grid1))
	{
		gridcpy(grid1, grid);
		print_grid(grid1);
		for (i = 0 ; i < SIZE_GRID ; i++)
			for (j = 0 ; j < SIZE_GRID ; j++)
				if (grid[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i >= 1)
						grid1[i - 1][j] += 1;
					if (i <= 1)
						grid1[i + 1][j] += 1;
					if (j >= 1)
						grid1[i][j - 1] += 1;
					if (j <= 1)
						grid1[i][j + 1] += 1;
				}
	}
}
/**
 * print_grid - print grid
 * @grid: grid to display
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * gridcpy - copy the content of grid
 * @grid1: src
 * @grid2: dest
 */
void gridcpy(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	for (i = 0 ; i < SIZE_GRID ; i++)
		for (j = 0 ; j < SIZE_GRID ; j++)
			grid2[i][j] = grid1[i][j];
}

/**
 * check_stable - check the stability of grid
 * @grid: given grid
 * Return: TRUE otherwise FALSE
 */
int check_stable(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0 ; i < SIZE_GRID ; i++)
		for (j = 0 ; j < SIZE_GRID ; j++)
			if (grid[i][j] > 3)
				return (FALSE);
	return (TRUE);
}
