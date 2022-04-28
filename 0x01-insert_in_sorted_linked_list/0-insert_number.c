#include "lists.h"

/**
  * insert_node - Function to add int node
  * @head: Double pointer
  * @n: int
  * Return: Added node
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_element;

	new_element = malloc(sizeof(listint_t));
	if (new_element == NULL)
	{
		return (NULL);
	}
	new_element->n = number;
	new_element->next = *head;
	*head = new_element;
	return (new_element);
}
