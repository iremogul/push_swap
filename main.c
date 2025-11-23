/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:24:21 by iogul             #+#    #+#             */
/*   Updated: 2025/11/23 15:03:27 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
}

void	sort_selection(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_new();
	stack_b = stack_new();
	if (!stack_a || !stack_b)
		return (clean_exit(stack_a, stack_b), 1);
	if (!parse_input_and_fill(argc, argv, stack_a))
		return (clean_exit(stack_a, stack_b), 1);
	if (is_sorted(stack_a))
		return (clean_exit(stack_a, stack_b), 0);
	index_list(stack_a);
	sort_selection(stack_a, stack_b);
	clean_exit(stack_a, stack_b);
	return (0);
}
