#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*stack_new(void);
t_node	*node_new(int value);
void	stack_push(t_stack *stack, int value);
int		stack_pop(t_stack *stack);
int		stack_peek(t_stack *stack);
int		is_empty(t_stack *stack);
int		stack_size(t_stack *stack);
void	stack_free(t_stack *stack);

int		parse_input_and_fill(int argc, char **argv, t_stack *stack_a);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		is_sorted(t_stack *stack);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

void	index_list(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif