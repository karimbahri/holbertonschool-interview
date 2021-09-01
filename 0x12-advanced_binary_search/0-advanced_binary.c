#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - advanced binary search algorithm
 * @array: given array
 * @size: length of the array
 * @value: value to search of
 * Return: index of value if found otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (search_recursively(array, 0, size - 1, value));
}

/**
 * search_recursively - binary search algorithm using recursion
 * @array: given array
 * @beg: first index
 * @end: last index
 * @value: value to search of
 * Return: index of value if found otherwise -1
 */
int search_recursively(int *array, size_t beg, size_t end, int value)
{
	int middle = 0;
	size_t i = 0;

	if (beg >= end)
		return (-1);
	middle = (beg + end) / 2;
	i = beg;
	printf("Searching in array: ");
	while (i < end)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("%d\n", array[i]);
	if (array[middle] == value)
	{
		if (beg == end - 1)
			return (middle);
	}
	if (array[middle] < value)
		return (search_recursively(array, middle + 1, end, value));
	else
		return (search_recursively(array, beg, middle, value));
}
