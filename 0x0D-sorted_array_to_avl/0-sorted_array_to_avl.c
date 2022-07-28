#include "binary_trees.h"
/**
 * sorted_array_to_avl - converts sorted array to avl
 * @array: pointer to the sorted array
 * @size: size of the array to convert to AVL tree
 * Return: pointer to the root node of the AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = recurse(array, 0, size - 1, NULL);

	return (root);
}

/**
 * recurse - utility function that constructs an AVL tree, recursively
 *
 * @array: pointer to the sorted array
 * @start: start index in the array
 * @end: end index in the array
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the AVL tree
 */

avl_t *recurse(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[mid];
	new_node->parent = parent;
	new_node->left = recurse(array, start, mid - 1, new_node);
	new_node->right = recurse(array, mid + 1, end, new_node);
	return (new_node);
}
