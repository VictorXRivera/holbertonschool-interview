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
	print_array(array, x);
}
/**
 * heapify - heapify function
 * @array: array of numbers
 * @n: n
 * @i: i
 * Return: void
 */
void heapify(int *arr, int h, int b, size_t size)
{
	int biggest = b;
	int left = 2 * b + 1;
	int right = 2 * b + 2;

	if (left < h && arr[left] > arr[biggest])
		biggest = left;

	if (right < h && arr[right] > arr[biggest])
		biggest = right;

	if (biggest != b)
	{
		swap(&arr[b], &arr[biggest], arr, size);
		heapify(arr, h, biggest, size);
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
	size_t b;

	if (array == NULL)
		return;

	for (b = size / 2 - 1; b > 0; b--)
		heapify(array, size, b - 1, size);

	for (b = size - 1; b > 0; b--)
	{
		swap(&array[0], &array[b], array, size);
		heapify(array, b, 0, size);
	}
}
