#include "shell.h"

/**
 **_strncpy - copies  stringg
 *@dest: destination string to be copied to
 *@src: the source stringg
 *@n: amount of char to be copied
 *Return: concatenated stringg
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 **_strncat - concatenatess 2 strings
 *@dest:  1st string
 *@src: 2nd  string
 *@n:  amount of bytes to be max  used
 *Return:  concatenated stringg
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates  character in a stringg
 *@s:  string to be parsedd
 *@c:  character to look forr
 *Return: (s) a pointer to  memoryy areaa
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
