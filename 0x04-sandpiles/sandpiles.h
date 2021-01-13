#ifndef __SAND__PILES__
#define __SAND__PILES__

#define FALSE 0
#define TRUE 1

#define SIZE_GRID 3
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_stable(int grid[3][3]);
void gridcpy(int grid1[3][3], int grid2[3][3]);
#endif
