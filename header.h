#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	int value;
	struct s_data *left;
	struct s_data *right;
}t_data;

t_data *creat_new_node(int value);
int	count_words(char *str, char *sep);
int	len_to_separator(char *str, char *sep);
int is_in_separator(char *sep, char c);
char *copy_words(char *str, char *sep);

#endif
