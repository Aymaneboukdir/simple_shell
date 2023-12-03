#include "shell.h"

/**
 **_strncpy - copy a string
 *@dest: the destination string to copy to
 *@src: the source series
 *@n: characters to be copied
 *Return: the sequential series
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
 **_strncat - connects two chains
 *@dest: the first series
 *@src: the second series
 *@n: the amount of bytes that will be used to the maximum
 *Return: the sequential series
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
 **_strchr - defines a character location in the series
 *@s: the series to parsed
 *@c: the character to look for
 *Return: (s) a pointer memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
