#include "shell.h"

/**
 * _myenv - Current printing environment
 * @info: The structure that contains possible arguments.
 *          fixed function prototype.
 * Return: Always 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}


/**
 * _mysetenv - Initialize the new environment variable,
 *             or modify existing one
 * @info: The structure contains possible arguments.
 *        fixed function prototype.
 *  Return: Always 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - Remove environmental variable
 * @info: The structure that contains possible arguments.
 *        fixed function prototype.
 * Return: Always 0
*/
int _myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
 * populate_env_list - Related population env linked
 * @info: The structure that contains possible arguments.
 *          fixed function prototypee.
 * Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
/**
 * _getenv - Gets the value of the environment variable
 * @info: The structure that contains possible arguments.
 * @name: The name of the environment variable
 *
 * Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}
