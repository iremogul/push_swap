#include "push_swap.h"

static void	sort_int_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*stack_to_array(t_stack *stack)
{
	int		*tab;
	t_node	*curr;
	int		i;

	tab = malloc(sizeof(int) * stack->size);
	if (!tab)
		return (NULL);
	curr = stack->top;
	i = 0;
	while (curr)
	{
		tab[i] = curr->data;
		curr = curr->next;
		i++;
	}
	return (tab);
}

void	index_list(t_stack *stack)
{
	int		*tab;
	t_node	*curr;
	int		i;

	tab = stack_to_array(stack);
	if (!tab)
		return ;
	sort_int_array(tab, stack->size);
	curr = stack->top;
	while (curr)
	{
		i = 0;
		while (i < stack->size)
		{
			if (curr->data == tab[i])
			{
				curr->data = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
	free(tab);
}

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	if (!stack || stack->size == 0)
		return (0);
	max = stack->size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head = stack_a->top;
			if (((head->data >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
