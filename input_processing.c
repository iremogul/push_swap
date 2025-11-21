#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

static int	count_words(char const *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= 0 || s[i - 1])
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == 0 || !s[i]) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (!split[j - 1])
				return (free_split(split, j - 1)); // Hata durumunda temizle
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

/* --- Input Processing İşlemleri --- */

static void	free_split_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	is_valid_format(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	// TODO: while ile 0 ları geç
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static int	to_int_safe(char *s, int *out)
{
	long long	n;
	int			sign;

	sign = 1;
	n = 0;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		n = n * 10 + (*s - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && -n < INT_MIN))
			return (0);
		s++;
	}
	*out = (int)(n * sign);
	return (1);
}

static int	has_duplicate(t_stack *a, int n)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->data == n)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static char	*join_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j++])
			len++;
		len++;
		i++;
	}
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		if (i < argc - 1)
			str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

static int	process_args_and_fill_stack(char **args, t_stack *stack_a)
{
	int	i;
	int	value;

	i = 0;
	while (args[i])
		i++;
	if (i == 0)
		return (0);
	while (--i >= 0)
	{
		if (!is_valid_format(args[i])
			|| !to_int_safe(args[i], &value)
			|| has_duplicate(stack_a, value))
			return (write(2, "Error\n", 6), 0);
		stack_push(stack_a, value);
	}
	return (1);
}

int	parse_input_and_fill(int argc, char **argv, t_stack *stack_a)
{
	char	*joined_args;
	char	**args;
	int		result;

	if (argc < 2)
		return (0);
	joined_args = join_args(argc, argv);
	if (!joined_args)
		return (0);
	args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!args)
		return (write(2, "Error\n", 6), 0);
	result = process_args_and_fill_stack(args, stack_a);
	free_split_array(args);
	return (result);
}