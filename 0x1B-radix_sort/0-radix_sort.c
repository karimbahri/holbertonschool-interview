#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorting array using radix algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int maxElement = max(array, size);
	int div = 0;

	for (div = 1 ; maxElement / div > 0 ; div *= 10)
	{
		count_sort(array, size, div);
		print_array(array, size);
	}
}

/**
 * max - return the biggest element of an array
 * @array: array to target
 * @size: size of the array
 * Return: max
 */
int max(int *array, size_t size)
{
	int _ = array[0];
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > _)
			_ = array[i];
	}
	return (_);
}

/**
 * count_sort - sorting using countSort
 * @array: array to target
 * @size: size of the array
 * @div: divided
 */
void count_sort(int *array, size_t size, int div)
{
	int *_array = NULL, countArray[10] = { 0 };
	size_t i = 0, index = 0;
	int addedNumber = 0;

	_array = malloc(sizeof(int) * size);

	if (!_array)
		return;

	for (i = 0 ; i < size; i++)
	{
		index = (array[i] / div) % 10;
		countArray[index]++;
	}

	for (i = 1 ; i < 10 ; i++)
	{
		addedNumber = countArray[i - 1];
		countArray[i] += addedNumber;
	}

	for (i = (size - 1) ; (int)(i) > -1; i--)
	{
		index = (array[i] / div) % 10;
		addedNumber = countArray[index];
		_array[addedNumber - 1] = array[i];
		countArray[index]--;
	}
	for (i = 0 ; i < size ; i++)
		array[i] = _array[i];
	free(_array);
}
