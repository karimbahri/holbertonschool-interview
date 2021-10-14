#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * cpy - copy array
 * @src: array to copy
 * @dest: destination
 * @size: array's length
 */
void cpy(int *src, int *dest, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}
}
/**
 * merge_sort - sorting array using merge_sort algorithm
 * @array: array to sort
 * @size: array's length
 */
void merge_sort(int *array, size_t size)
{
	int *merged = NULL;

	if (!array)
		return;
	if (size < 2)
		return;
	
	merged = malloc(size * sizeof(int));
	if (!merged)
		return;

	merge_wrap(array, merged, size);
	free(merged);
}

/**
 * merge_wrap - sort array using merge array algorithm
 * @array: array to sort
 * @merged: tmp copy of array
 * @size: array's length
 */
void merge_wrap(int *array, int *merged, size_t size)
{
	int middle = 0;

	if (size < 2)
		return;

	middle = size / 2;
	merge_wrap(array, merged, middle);
	merge_wrap(array + middle, merged, size - middle);
	merge(array, merged, middle, size);
}

/**
 * merge - merge array
 * @array: array to merge
 * @merged: copy of array
 * @middle: middle
 * @size: array length
 */
void merge(int *array, int *merged, int middle, int size)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);

	for (i = 0, j = middle, k = 0; k < size; k++)
	{
		if (j == size)
		{
			merged[k] = array[i];
			i++;
		}
		else if (i == middle)
		{
			merged[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			merged[k] = array[j];
			j++;
		}
		else
		{
			merged[k] = array[i];
			i++;
		}
	}
	cpy(merged, array, size);
	printf("[Done]: ");
	print_array(merged, size);
}
