#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 1 if no error occur otherwise 98
 */
int main(int argc, char **argv)
{
	unsigned long long int nb1 = 0, nb2 = 0;

	if (argc < 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (!check_digit(argv[1]) || !check_digit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	nb1 = strtoull(argv[1], NULL, 10);
	nb2 = strtoull(argv[2], NULL, 10);

	printf("%lld\n", nb1 * nb2);
	return (1);
}

/**
 * check_digit - check if a string is digit
 * @number: string to check
 * Return: 1 if digit 0 otherwise
 */
int check_digit(char *number)
{
	int i = 0;

	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
