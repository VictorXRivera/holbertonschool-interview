#include "sort.h"
void siftDown(int key, int num[], int root, int last)
{
	int larger = 2 * root;
	while (larger <= last)
	{
		if (larger < last)
		{
			if (num[larger + 1] > num[larger])
				larger++;
		}
		if (key >= num[larger])
			break;

		num[root] = num[larger];
		root = larger;
		larger = 2 * root;
	}
	num[root] = key;
}

void heap_sort(int *array, size_t size)
{
	for (int h = size / 2; h >= 1; h--)
		siftDown(array[h], array, h, size);
	for (int k = size; k > 1; k--)
	{
		int item = array[k];
		array[k] = array[1];
		siftDown(item, array, 1, k - 1);
	}
}
