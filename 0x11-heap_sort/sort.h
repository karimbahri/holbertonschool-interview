#ifndef __HEAP_SORT__
#define __HEAP_SORT__
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap_int(int *_, int *__);
void array_heapify(int *array, int index, int len, int size);
#endif