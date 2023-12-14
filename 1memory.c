#include "shell.h"

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

/**
 * build_history_list - adds the entry to a list linked to the data
 * @info: The Structure contains possible arguments.
 * @buf: buffer
 * @linecount: history linecount, histcount
 *
 * Return: Always 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

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
