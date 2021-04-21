#include "sort.h"
/**
 * swap - swapping function
 * @v: value to swap
 * @r: value to swap
 * @x: numbers to be printed
 * Return: void
 */
void swap(int *v, int *r, int *array, size_t x)
{
	int temp = *v;
	*v = *r;
	*r = temp;
	print_array(array, x)
}
/**
 * heapify - heapify function
 * @array: array of numbers
 * @n: n
 * @i: i
 * Return: void
 */
void heapify(int *arr, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest], arr, size);
		heapify(arr, n, largest, size);
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
	if (array == NULL)
		return;

	for (size_t i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i - 1, size);

	for (size_t i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}
