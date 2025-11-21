#include "push_swap.h"
#include <unistd.h>
void swap_core(t_stack *stack)
{
    t_node *first;
    t_node *second;
    int tmp;
    
    if(is_empty(stack)|| stack ->size <2)
        return;
    
    first = stack->top;
    second = stack-> top->next;

    tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}
void sa(t_stack *stack_a)
{
    swap_core(stack_a);
    write(1, "sa\n", 3);
}
void sb(t_stack *stack_b)
{
    swap_core(stack_b);
    write(1, "sb\n", 3);
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_core(stack_a);
    swap_core(stack_b);
    write(1,"ss\n", 3);
}