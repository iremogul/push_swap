#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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




#endif