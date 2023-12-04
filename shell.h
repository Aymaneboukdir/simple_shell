#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked listt
 * @num: the number fieldd
 * @str: a string
 * @next: points to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contain pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer structt
* @line_count: error countt
 * @err_num: error code for exit()s
 * @linecount_flag: if on count  line of input
 * @fname: program filename
 * @env: linked list local copy of environn
 * @environ: custom modified copy ofe  environ from LL env
 * @history: history node
 * @alias: alias node
 * @arg: a string generated getline vcontaining arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for current command
 * @argc: argument countt
 * @env_changed: on if environn was changed
 * @status: return status of last exec'd comd
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd from which to read line inputt
 * @histcount: history line no. count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains builtin string & related functionn
 * @type:  builtinn command flagg
 * @func:  functionn
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_2shell_loop.c */
int hsh(info_t *, char **);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int find_builtin(info_t *);

/* toem_2parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
void *_realloc(void *, unsigned int, unsigned int);

/* loophsh.c */
int loophsh(char **);

/* toem_2errors.c */
void _eputs(char *);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_2string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);

/* toem_2string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strcat(char *, char *);


/* toem_2exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_2tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);
int replace_string(char **, char *);

/* toem_2realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);


/* toem_1memory.c */
int bfree(void **);

/* toem_1_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _atoi(char *);

/* toem_2errors1.c */
int _eputchar(char);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _erratoi(char *);

/* toem_1builtin.c */
int _myexit(info_t *);
int _myhelp(info_t *);
int _isalpha(int);

/* toem_1builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);
int _mycd(info_t *);

/*toem_1getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_1getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_1environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_1getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_1history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_1lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_1lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_2vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
#endif
