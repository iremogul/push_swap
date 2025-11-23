/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:52:37 by iogul             #+#    #+#             */
/*   Updated: 2025/11/23 15:02:40 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_format(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	if (*s == '0')
	{
		while (*s == '0')
			s++;
		if (!*s)
			return (1);
	}
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	to_int_safe(char *s, int *out)
{
	long long	n;
	int			sign;

	sign = 1;
	n = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		n = n * 10 + (*s - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n) < INT_MIN))
			return (0);
		s++;
	}
	*out = (int)(n * sign);
	return (1);
}

int	has_duplicate(t_stack *a, int n)
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

int	process_args_and_fill_stack(char **args, t_stack *stack_a)
{
	int	i;
	int	value;

	i = 0;
	while (args[i])
		i++;
	if (i == 0)
		return (write(2, "Error\n", 6), 0);
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
