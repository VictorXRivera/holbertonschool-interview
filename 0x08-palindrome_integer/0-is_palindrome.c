#include "palindrome.h"
/**
 * is_palindrome - function checking if unsigned int is palindrome
 * @n: unsigned int
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long palin;

	palin = 10;
	while (n / pow_10 >= 10)
		pow_10 *= 10;

	while (n >= 10)
	{
		if (n % 10 != n / pow_10)
			return (0);
		n /= 10;
		pow_10 /= 10;
		n = n - ((n / (pow_10)) * pow_10);
		pow_10 /= 10;
	}
	return (1);
}
