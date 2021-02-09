#include "palindrome.h"
/**
 * is_palindrome - Function to check in unsigned long int is palindrome
 * @n - number to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev_num = 0;
	unsigned long remainder;
	unsigned long original_num;

	original_num = n;

	while (n != 0)
	{
		remainder = n % 10;
		rev_num = rev_num * 10 + remainder;
		n /= 10;
	}

	if (original_num == rev_num)
		return (1);
	else
		return (0);
}
