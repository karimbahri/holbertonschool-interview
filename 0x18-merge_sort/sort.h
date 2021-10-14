#ifndef __MERGE__
#define __MERGE__
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *merged, int middle, int size);
void merge_wrap(int *array, int *merged, size_t size);
void cpy(int *src, int *dest, int size);
#endif
