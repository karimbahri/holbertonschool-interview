#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_int - swap the value of two integers
 * @_: first integer
 * @__: second integer
 */
void swap_int(int *_, int *__)
{
	int ___ = *_;
	*_ = *__;
	*__ = ___;
}

/**
 * heap_sort - sort array using heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	for (i = (size / 2) - 1 ; i > -1 ; i--)
		array_heapify(array, i, size, size);

	for (i = (size - 1) ; i ; i--)
	{
		/*SWAP ARRAY[i] and array[0]*/
		/**
		* array[i] = aux;
		* array[i] = array[0];
		* array[0] = aux;
		**/
		swap_int(&array[i], array);
		print_array(array, size);

		/*heapify*/
		array_heapify(array, 0, i, size);
	}
}

/**
 * array_heapify - heapify array
 * @array: array to heapify
 * @index: index supposed as largest element
 * @len: array size
 * @size: size of the array
 */
void array_heapify(int *array, int index, int len, int size)
{
	int max = index, right = (2 * index) + 2;
	int left = (2 * index) + 1;

	if (array[left] > array[max])
		if (left < len)
			max = left;

	if (array[right] > array[max])
		if (right < len)
			max = right;

	if (index != max)
	{
		swap_int(&array[max], &array[index]);
		print_array(array, size);
		array_heapify(array, max, len, size);
	}
}
