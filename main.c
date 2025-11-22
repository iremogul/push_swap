#include "push_swap.h"

static void	clean_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
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
	clean_exit(stack_a, stack_b);
	return (0);
}