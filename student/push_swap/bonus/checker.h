#ifndef CHECKER_H
#define CHECKER_H
    
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../../libft/libft.h"
#include "../push_swap.h"
#include "../../get_next_line/get_next_line.h"

void	checker_rr(t_stack **stack_a, t_stack **stack_b);
void	checker_rrr(t_stack **stack_a, t_stack **stack_b);
void	checker_sa_sb(t_stack **stack);
void	checker_ss(t_stack **stack_a, t_stack **stack_b);
void	checker_pa_pb(t_stack **stack_dest, t_stack **stack_src);
void	checker_ra_rb(t_stack **stack);
void	checker_rra_rrb(t_stack **stack);

#endif