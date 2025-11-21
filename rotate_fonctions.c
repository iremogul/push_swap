#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
void rotate_core(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if(!stack || stack->size <2)
        return;

    first = stack->top;
    stack->top = first->next;
    last = stack->top;
    while(last->next)
        last = last->next;

    last->next =first;
    first->next = NULL;
}
void ra(t_stack *stack_a)
{
    rotate_core(stack_a);
    write(1, "ra\n", 3);
}
void rb(t_stack *stack_b)
{
    rotate_core(stack_b);
    write(1, "rb\n", 3);
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate_core(stack_a);
    rotate_core(stack_b);
    write(1, "rr\n", 3);
}