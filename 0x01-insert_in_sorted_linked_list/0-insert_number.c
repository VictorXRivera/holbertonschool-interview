#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - Function to insert node in
 * sorted linked list
 * @head: Pointer to the list I will add to
 * @number: Value of the new node
 * Return: the address of the new node, 
 * or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current_node;

	current_node = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return NULL;
	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else if ((*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (current_node->next != NULL && current_node->next->n <= number)
			current_node = current_node->next;
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	return (new_node);
}
