#include "lists.h"

/**
 * find_listint_loop - method that finds loop
 * inside linked list
 * @head: head of the list
 * Return: The address of the node where the loop starts
 * or NULL if there is no loop
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr1 = head;
	listint_t *ptr2 = head;

	if (!head || !head->next)
		return (NULL);

	while (ptr2 != NULL && ptr2->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;

		if (ptr1 == ptr2)
		{
			ptr1 = head;
			while (ptr1 != ptr2)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}

			return (ptr2);
		}
	}

	return (NULL);
}
