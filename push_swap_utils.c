    #include "push_swap.h"
#include <stdlib.h>

t_stack *stack_new(void)//(void)-> dışarıdan veri almaz,sadece stack oluşturur.
{
    t_stack *new_stack;
    new_stack= (t_stack*)malloc(sizeof(t_stack));

    if(new_stack == NULL)
        return NULL;
    new_stack -> top =NULL;
    new_stack -> size =0;
    return(new_stack);

}
t_node *node_new(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node==NULL)
        return NULL;

    new_node ->data = value;
    new_node ->next = NULL;

    return(new_node);
    
}
int is_empty(t_stack *stack)
{
    if(stack == NULL || stack ->top == NULL)
        return 1;
    return 0;
}
//başa elaman ekleme fonk

int stack_size(t_stack *stack)
{
    if (stack == NULL)
        return 0;
    
    return (stack ->size );
}
//program sonunda tün stack ve node ları temizler
void stack_free(t_stack *stack)
{
    t_node *current;
    t_node *next_node;

    if(stack == NULL)
        return;

    current = stack->top;

    while(current != NULL)
    {
        next_node = current ->next;
        free(current);
        current = next_node;
    }
    free(stack);
    
}

