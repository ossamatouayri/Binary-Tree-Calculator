#include "header.h"

int	len_to_separator(char *str, char *sep)
{
	int i;

	i = 0;
	if (is_in_separator(sep, str[i]))
		return (1);
	while (str[i])
	{
		if (is_in_separator(sep, str[i]))
			return (i);
		i++;
	}
	return (i);
}

int is_in_separator(char *sep, char c)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *copy_words(char *str, char *sep)
{
	int i;
	int len;
	char *new;

	len = len_to_separator(str, sep);
	if (!(new = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	count_words(char *str, char *sep)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_separator(sep, str[i]))
		{
			count++;
			i++;
		}
		if (str[i])
			count++;
		while (str[i] && !is_in_separator(sep, str[i]))
			i++;
	}
	return (count);
}

char **split(char *str, char *sep)
{
	int		i;
	int		word_len;
	char	**arr;

	if (!str)
		return (NULL);
	word_len = count_words(str, sep);
	if (!(arr = malloc((word_len + 1) * sizeof (char *))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_in_separator(sep, *str))
		{
			arr[i] = copy_words(str, sep);
			i++;
			str++;
		}
		if (*str)
		{
			arr[i] = copy_words(str, sep);
			i++;
		}
		while (*str && !is_in_separator(sep, *str))
			str++;
	}
	arr[i] = NULL;
	return (arr);
}


int check_errors(char **arr)
{
	int i;

	i = 0;
	if (!check_closed_parantheses(arr))
		return (0);
	if (!is_digit(arr[i]))
		return (printf("syntax error near unexpected token `%s'\n", arr[i]), 0);
	while (arr[i])
	{
		if (!is_digit(arr[i]) && !is_digit(arr[i + 1]))
			return (printf("syntax error near unexpected token `%s'\n", arr[i]), 0);
		if (!is_other_char(arr[i]))
			return (printf("syntax error near unexpected token `%s'\n", arr[i]), 0);
		i++;
	}
	if (!is_digit(arr[i - 1]))
		return (printf("syntax error near unexpected token `%s'\n", arr[i - 1]), 0);
	return (1);
}

int main(int ac, char **av)
{
	char **arr;
	(void) ac;

	arr = split(av[1], "+()");
	if (!check_errors(arr))
		return (1);
}
