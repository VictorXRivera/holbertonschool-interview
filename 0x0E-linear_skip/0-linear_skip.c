#include "search.h"
/**
 * search - helper function to search for the value in the
 * linked list
 * @i: the previous pointer
 * @j: the actual pointer
 * @value: value to search
 * Return: Node where the value is or NULL if the value couldn't be find
 */
skiplist_t *search(skiplist_t *i, skiplist_t *j, int value)
{
	while (i && i->index <= j->index)
	{
		printf("Value checked at index [%lu] = [%i]\n", i->index,
		       i->n);
		if (i->n == value)
			return (i);
		i = i->next;
	}
	return (NULL);
}

/**
 * linear_skip - function that searches for a value 
 * in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: Node where the value is or NULL if the value couldn't be find
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *actual, *prev;
	size_t act_i, pre_i;

	if (!list)
		return (NULL);

	actual = list;
	while (actual->express != NULL)
	{
		prev = actual;
		actual = actual->express;
		act_i = actual->index;
		pre_i = prev->index;
		printf("Value checked at index [%lu] = [%i]\n", act_i,
		       actual->n);
		if (prev->n > value && prev->index == 0)
			return (NULL);
		if (actual->n >= value)
			break;
	}
	if (!actual->express && actual->n < value)
	{
		prev = actual;
		pre_i = prev->index;
		while (actual->next)
			actual = actual->next;
		act_i = actual->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", pre_i, act_i);
	return (search(prev, actual, value));
}
