#include "header.h"

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
