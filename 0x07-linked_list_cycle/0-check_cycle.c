#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * check_cycle - function checking if singly linked list has cycle in it
 * @list: list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *p_1 = list, *p_2 = list;

	while (p_1 && p_2 && p_2->next)
	{
		p_1 = p_1->next;
		p_2 = p_2->next->next;
		if (p_1 == p_2)
		{
			return (1);
		}
	}
	return (0);
}
