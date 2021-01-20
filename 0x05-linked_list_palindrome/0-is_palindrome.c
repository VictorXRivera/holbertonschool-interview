#include "lists.h"
/**
 * recursive_check - helper function to compare left and right data
 * @left: double pointer to starting/left node
 * @right: pointer to right node
 * Return: result
 */
int recursive_check(listint_t **left, listint_t *right)
{
    if (right == NULL)
        return 1;
 
    int result = recursive_check(left, right->next) &&
            ((*left)->n == right->n);
    (*left) = (*left)->next;
 
    return result;
}

/**
 * is_palindrome - function to check if singly linked list 
 * is a palindrome
 * @head: start of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered palindrome
 */
int is_palindrome(listint_t **head)
{
	return recursive_check(&(*head), *head);
}