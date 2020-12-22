#include "binary_trees.h"
/**
 * heap_insert - function to insert max value into heap
 * @root - a double pointer to the root node of the Heap
 * @value - value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int temp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	else
		return (NULL);

	while (new_node->parent && new_node->parent->n < new_node->n)
	{
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
