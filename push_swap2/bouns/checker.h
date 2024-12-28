#ifndef CHECKER_H
#define CHECKER_H
    
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../../libft/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sa_sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa_pb(t_stack **stack_dest, t_stack **stack_src);
void	ra_rb(t_stack **stack);
void	rra_rrb(t_stack **stack);

void	add_front(t_stack **stack, t_stack *node);
void	add_back(t_stack **stack, t_stack *node);

#endif