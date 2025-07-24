#include "header.h"

int check_digit(char c)
{
	if ((c >= '0' && c <= '9') || (c == '(' || c == ')'))
		return (1);
	return (0);
}

int is_digit(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!check_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_data *creat_new_node(int value)
{
	t_data *new;

	new = malloc(sizeof (t_data));
	if (!new)
		return (NULL);
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
