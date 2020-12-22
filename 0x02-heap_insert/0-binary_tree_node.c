#include "binary_trees.h"

/**
 * binary_tree_node - function that adds a node to a binary tree
 * @parent: The parent of binary tree
 * @value: the value to put in the node
 * Return: Pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;

	if (parent == NULL)
		return (node);

	if (parent->n > value)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
