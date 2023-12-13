#include "shell.h"
/**
 * _isalpha - check for alph char
 * @c: the characters used to input.
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _myexit - exits shell
 * @info: The structure containing the possible argument.
 * fixed function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
*/
int _myexit(info_t *info)
{
int exitcheck;

if (info->argv[1]) /* If there is an exit arguement */
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}



/**
 * _myhelp - Change the current process directory.
 * @info: The structure that contains possible arguments.
 * constant function prototypee.
 * Return: Always 0
*/
int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: The structure that contains possible arguments. Used to maintain
 *        fixed function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}
