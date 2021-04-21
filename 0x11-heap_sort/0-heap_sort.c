#include "sort.h"
/**
 * swap - swapping function
 * @v: value to swap
 * @r: value to swap
 * Return: void
 */
void swap(int *v, int *r)
{
	int temp = *v;
	*v = *r;
	*r = temp;
}
/**
 * heapify - heapify function
 * @array: array of numbers
 * @n: n
 * @i: i
 * Return: void
 */
void heapify(int *array, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}
/**
 * heap_sort - heap sort algorithm
 * @array: array
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}
