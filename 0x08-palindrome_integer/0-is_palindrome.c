#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * reverse_integer - reverse given integer
 * @integer: number to reverse
 * Return: reversed integer
 */
_U_Long_ reverse_integer(_U_Long_ integer)
{
	_U_Long_ reverse = 0;

	while (integer)
	{
		reverse = (reverse * 10) + (integer % 10);
		integer /= 10;
	}
	return (reverse);
}
/**
 * is_palindrome - check if a number is palindrome
 * @n: number to check
 * Return: 1 if true 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	if (n == reverse_integer(n))
		return (1);
	return (0);
}
