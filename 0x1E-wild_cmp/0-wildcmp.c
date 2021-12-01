#include "holberton.h"

/**
 * wildcmp - check if s1 and s2 are identical
 * @s1: first string
 * @s2: second string
 * Return: 1 if true 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	else if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));

	else if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	else
		return (0);
}
