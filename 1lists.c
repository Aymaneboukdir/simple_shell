#include "shell.h"

/**
 * get_node_index - gets the index of the node
 * @head: pointer to the head of the list
 * @node: pointer to the node
 *
 * Return: index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: Address of the pointer to the head node
 * @str: node string field
 * @num: index of the node used by history
 * Return: list size
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);

node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}
/**
 * add_node - adds a node to start the list
 * @head: Address of the pointer to the head node
 * @str: string field of node
 * @num: index of the node used by history
 *
 * Return: list size
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;

if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}

/**
 * delete_node_at_index - delete the node at the specified index
 * @head: The address of the pointer to the first node
 * @index: index of the node to be deleted
 *
 * Return: 1 on success, 0 on failure
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!head || !*head)
return (0);

if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}
/**
 * print_list_str - prints only the string element in the linked list list_t
 * @h: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
