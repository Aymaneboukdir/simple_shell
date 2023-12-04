#include "shell.h"

/**
 * interactive - yields true if shell is interactive
 * @info: the structure address
 *
 * Return: 1 if interactive mode, 0 otherwisee
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _atoi - convert a string to the correct number
 * @s: the string converted
 * Return: 0 if no nos in string, converted no otherwise
*/

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}

/**
 * is_delim - check if character is a delimeter
 * @c: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
