#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int *r, int *array, size_t x);
void heapify(int *arr, int h, int b, size_t size);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
#endif /*SORT_H*/
