#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_b))
		return ;
	value = stack_pop(stack_b);
	stack_push(stack_a, value);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (is_empty(stack_a))
		return ;
	value = stack_pop(stack_a);
	stack_push(stack_b, value);
	write(1, "pb\n", 3);
}