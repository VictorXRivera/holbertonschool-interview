#include "search_algos.h"
/**
 * print_array - function to print out the search
 * @array: array
 * @left: left side of array
 * @right: right side of array
 * Return: Void
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}
/**
 * binary_search - recursive binary search of array
 * @array: array to search
 * @ele_1: first elements of array
 * @ele_2: last elements of array
 * @value: value
 * Return: index of the first value in the array or -1 on fail
 */
int binary_search(int *array, int ele_1, int ele_2, int value)
{
	int mid;

	print_array(array, ele_1, ele_2);

	mid = (ele_2 - ele_1) / 2 + ele_1;

	if (ele_1 == ele_2)
		return (-1);

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (array[mid] >= value)
		return (binary_search(array, ele_1, mid, value));

	if (array[mid] <= value)
		return (binary_search(array, mid + 1, ele_2, value));

	return (-1);
}
/**
 * advanced_binary - advanced search
 * @array: array to search
 * @size: size of array
 * @value: value to return
 * Return: index of 1st value in array or -1 on fail
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}
