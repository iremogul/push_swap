#include "push_swap.h" 
void index_list(t_stack *stack)
{
    t_node *i;
    t_node *j;
    int index;

    i= stack;
    while(i)
    {
        index = 0;
        j= stack;

        while (j)
        {
            if(i->data > j->data)
                index++;
            j= j->next;
        }
        i->data=index;
        i = i->next;

    }
}