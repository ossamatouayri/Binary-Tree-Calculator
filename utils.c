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

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int check_closed_parantheses(char **arr)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], "("))
			count++;
		else if (!ft_strcmp(arr[i], ")"))
			count--;
		if (count < 0)
			return (printf("syntax error unclosed parantheses `%s'\n", arr[i]),0);
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int check_other_char(char c)
{
	if ((c != '+' && c != '(' && c != ')') && (c <= '0' && c >= '9'))
		return (0);
	return (1);
}

int is_other_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!check_other_char(str[i]))
			return(0);
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
