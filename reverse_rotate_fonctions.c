#include <unistd.h>
#include "push_swap.h"
void reverse_rotate_core(t_stack *stack)
{
    t_node *prev;
    t_node *last;

    if (!stack || stack->size < 2)
        return;

    prev = NULL;
    last = stack->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top =last;

}
void rra(t_stack *stack_a)
{
    reverse_rotate_core(stack_a);
    write(1, "rra\n", 4);
}
void rrb(t_stack *stack_b)
{
    reverse_rotate_core(stack_b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate_core(stack_a);
    reverse_rotate_core(stack_b);
    write(1, "rrr\n", 4);
}