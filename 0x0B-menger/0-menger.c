#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * menger - menger squares
 * @level: level
 */
void menger(int level)
{
	int i = 0, j = 0, length = pow(3, level);
	int tmp_i = 0, tmp_j = 0;
	int boolean = 0;

	if (level < 0)
		return;
	for (i = 0 ; i < length ; i++)
	{
		for (j = 0 ; j < length ; j++)
		{
			tmp_i = i;
			tmp_j = j;
			while (tmp_i && tmp_j)
			{
				boolean = ((tmp_i % 3 == 1) && (tmp_j % 3 == 1));
				if (boolean)
				{
					printf(" ");
					break;
				}
				tmp_i /= 3;
				tmp_j /= 3;
			}
			if (!boolean)
				printf("#");

		}
		printf("\n");
	}
}
