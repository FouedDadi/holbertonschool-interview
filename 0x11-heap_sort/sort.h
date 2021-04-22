#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void build_heap(int *array, int i, int j, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *i, int *j);
void print_array(const int *array, size_t size);

#endif
