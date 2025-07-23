#include "header.h"

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
	// int		i;
	int		word_len;
	// char	**arr;

	if (!str)
		return (NULL);
	word_len = count_words(str, sep);
	printf("Number of words is:%d\n", word_len);
	return (NULL);
}

int main(int ac, char **av)
{
	(void) ac;
	split(av[1], "+()");
}
