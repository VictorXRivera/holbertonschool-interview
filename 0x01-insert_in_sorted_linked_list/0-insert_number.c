#include "lists.h"

/**
  * insert_node - Function to add int node
  * @head: Double pointer
  * @number: int
  * Return: Added node
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_element;
	listint_t *temp;

	if (head == NULL)
		return (NULL);

	new_element = malloc(sizeof(listint_t));
	if (new_element == NULL)
		return (NULL);

	new_element->n = number;
	new_element->next = NULL;

	if (*head == NULL)
		*head = new_element;
	else if (number < (*head)->n)
	{
		new_element->next = *head;
		*head = new_element;
	}
	else
	{
		temp = *head;
		while (temp->next && temp->next->n < number)
		{
			temp = temp->next;
		}
		new_element->next = temp->next;
		temp->next = new_element;
	}
	return (new_element);
}
