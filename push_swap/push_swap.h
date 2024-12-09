#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <limits.h> 

typedef struct s_stack
{
	int				val;
	int				index;
	int				position;
	int				cost;
	int 			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
} t_stack;

int			find_mite(t_stack **stack, int n );
int 		smallest_num(t_stack **stack);
int			to_mite(t_stack **stack, int les);
int			last_node(t_stack *stack);
int			stack_size(t_stack *stack);
int			list_sorted(t_stack **stack);

void		sa_sb(t_stack **stack, char str);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa_pb(t_stack **stack_dest, t_stack **stack_src, char str);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		ra_rb(t_stack **stack, char str);
void		rra_rrb(t_stack **stack, char str);
void		find_rr(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		find_rrr(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		add_back(t_stack **stack, t_stack *node);
void		add_front(t_stack **stack, t_stack *node);
void		min_on_top(t_stack **stack);
void		prep_for_push(t_stack **stack, t_stack *top_node, char ch);
void		put_indexs(t_stack *stack);
void		find_target(t_stack *b, t_stack *a);
void		set_target_b(t_stack *a, t_stack *b);
void		nodes_cost(t_stack *stack_b, t_stack *stack_a);
void		set_cheapest(t_stack *stack);
void		sort_three(t_stack **stack_a);

t_stack		*create_new_node(int num);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
t_stack		*get_cheapest(t_stack *stack);
#endif