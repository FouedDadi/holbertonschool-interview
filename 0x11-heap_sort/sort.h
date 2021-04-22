#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void heapify(int *array, int a, int b, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void print_array(const int *array, size_t size);

#endif
