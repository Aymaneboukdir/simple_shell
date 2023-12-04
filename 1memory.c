#include "shell.h"

/**
 * bfree - free the address of the NULL pointer
 * @ptr: cursor address to freeze
 *
 * Return: 1 if freed, otherwise 0.
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
/**
 * print_alias - print the alias string
 * @node: node alias
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}
