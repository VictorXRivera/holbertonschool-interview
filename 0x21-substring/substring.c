#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"


/**
 * find_substring - Entry point
 * @s: char const
 * @words: char const
 * @nb_words: int
 * @n: int
 * Return: 0, 1
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k, curent, count, string_len, lenghts, checks;
	int *result, *matched;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	string_len = strlen(s);
	lenghts = strlen(words[0]);
	result = malloc(string_len * sizeof(int));
	matched = malloc(nb_words * sizeof(int));
	if (!matched)
		return (NULL);
	if (!result)
		return (NULL);
	for (i = count = 0; i <= string_len - nb_words * lenghts; i++)
	{
		memset(matched, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				curent = i + j * lenghts;
				checks = strncmp(s + curent, *(words + k), lenghts);
				if (!*(matched + k) && !checks)
				{
					*(matched + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(result + count) = i, count += 1;
	}
	free(matched);
	*n = count;
	return (result);
}
