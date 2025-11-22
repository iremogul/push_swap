#include "push_swap.h"
void stack_push(t_stack *stack, int value)
{
    t_node *new_node;
    if (stack == NULL)
        return;

    new_node = node_new(value);

    if(new_node == NULL)
        return;
    new_node -> next = stack ->top;
    stack->top = new_node;

    stack ->size++;
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
