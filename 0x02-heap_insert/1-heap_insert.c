#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: store in the node to be inserted
 * Return: pointer to the inserted node or NULL if failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *temp = *root;

	new_node = malloc(sizeof(heap_t));

	if(!root)
		return (NULL);

	if(!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

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
