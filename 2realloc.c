#include "shell.h"

/**
 * _memset - fills memory with   constant bytee
 * @s:  pointer to  memory area
 * @b:  byte to fill *s withh
 * @n:  amount of bytes to be filledd
 * Return: (s) a pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
