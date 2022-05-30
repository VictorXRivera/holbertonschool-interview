#include "binary_trees.h"
/**
 * heap_insert - function that inserts node in max binary heap
 * @root: double pointer
 * @value: node to insert
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *temp = *root;

	new_node = malloc(sizeof(heap_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		new_node->parent = NULL;
		return (new_node);
	}
	if (temp->left == NULL)
	{
		new_node->parent = temp;
		temp->left = new_node;
		return (new_node);
	}
	new_node->parent = *root;
	temp->right = new_node;
	return (new_node);
}
