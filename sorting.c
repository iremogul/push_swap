#include "push_swap.h"
#include "push_swap.h"

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

void	sort_3(t_stack *a)
{
	t_node	*node;
	int		x;
	int		y;
	int		z;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	node = a->top;
	x = node->data;
	y = node->next->data;
	z = node->next->next->data;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	get_min_index(t_stack *a)
{
	int		min;
	int		idx;
	int		i;
	t_node	*curr;

	min = a->top->data;
	idx = 0;
	i = 0;
	curr = a->top;
	while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (idx);
}

static void	bring_min_to_top(t_stack *a)
{
	int	idx;
	int	size;

	idx = get_min_index(a);
	size = a->size;
	if (idx <= size / 2)
	{
		while (idx > 0)
		{
			ra(a);
			idx--;
		}
	}
	else
	{
		while (idx < size)
		{
			rra(a);
			idx++;
		}
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	bring_min_to_top(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	bring_min_to_top(a);
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}
 