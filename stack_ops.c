/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iogul <iogul@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:30:30 by iogul             #+#    #+#             */
/*   Updated: 2025/11/23 14:52:47 by iogul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = node_new(value);
	if (!new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*to_delete;
	int		data;

	if (!stack || is_empty(stack))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	to_delete = stack->top;
	data = to_delete->data;
	stack->top = to_delete->next;
	free(to_delete);
	stack->size--;
	return (data);
}

int	stack_peek(t_stack *stack)
{
	if (!stack || is_empty(stack))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (stack->top->data);
}

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack)
		return (1);
	curr = stack->top;
	while (curr && curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
