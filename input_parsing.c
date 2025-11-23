/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:05:59 by iogul             #+#    #+#             */
/*   Updated: 2025/11/23 14:47:48 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_len(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			j++;
			len++;
		}
		len++;
		i++;
	}
	return (len);
}

char	*join_args(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = malloc(sizeof(char) * get_total_len(argc, argv));
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

int	contains_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	parse_input_and_fill(int argc, char **argv, t_stack *stack_a)
{
	char	*joined_args;
	char	**args;
	int		result;
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!contains_digit(argv[i]))
			return (write(2, "Error\n", 6), 0);
		i++;
	}
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

void	free_split_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
