#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - a function that find all possible substrings
 * @s: string to scan
 * @words: array of words
 * @nb_words: length of words
 * @n: address of the number of elements
 * Return: return an array of index otherwise NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int length_s = 0, length_words = 0, *arrayOfScans, *arrayOfWords;
	int i = 0, j, k, l = 0;
	int curr, sub;

	length_words = strlen(words[0]), length_s = strlen(s);
	arrayOfWords = malloc(sizeof(int) * nb_words);
	if (!arrayOfWords)
		return (NULL);
	arrayOfScans = malloc(sizeof(int) * length_s);
	if (!arrayOfScans)
		return (NULL);
	while (i <= (length_s - (length_words * nb_words)))
	{
		memset(arrayOfWords, 0, sizeof(int) * nb_words), j = 0;
		while (j < nb_words)
		{
			for (k = 0 ; k < nb_words ; k++)
			{
				curr = i + j * length_words;
				sub = strncmp(s + curr, words[k], length_words);
				if (!sub && !arrayOfWords[k])
				{
					arrayOfWords[k] = 1;
					break;
				}
			}
			if (nb_words == k)
				break;
			j++;
		}
		if (nb_words == j)
		{
			arrayOfScans[l] = i;
			l++;
		}
		i++;
	}
	free(arrayOfWords);
	*n = l;
	return (arrayOfScans);
}
