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
}	t_stack;

t_stack		*create_new_node(int num);
int			list_sorted(t_stack **stack);
int			stack_size(t_stack *stack);
int			last_node(t_stack *stack);
void		add_front(t_stack **stack_a, t_stack *node);
void		add_back(t_stack **stack, t_stack *node);
void		sa_sb(t_stack **stack, char str);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa_pb(t_stack **stack_dest, t_stack **stack_src, char str);
void		ra_rb(t_stack **stack, char str);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra_rrb(t_stack **stack, char str);
void		rrr(t_stack **stack, t_stack **stack_b);
int	        ft_int_valid(t_stack *stack_a, int num);
int	        ft_atoi(const char *str);
int	        ft_isdigit(int ch);
void	print_stack(t_stack *stack, t_stack *stack_b);
void	sort_three(t_stack **stack_a);


void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a;
	t_stack *b;

	a = stack_a;
	b = stack_b;
	printf("stack_a		stack_b\n\n");
	while (a || b)
	{
		if (!a)
		{
			printf("<   -  >	<   %d  >\n", b -> val);
			b = b -> next;
		}
		else if (!b)
		{
			printf("<    %d  >	<   -  >\n", a -> val);
			a = a -> next;
		}
		else if(a && b)
		{
			printf("<   %d  >	<   %d  >\n", a -> val, b -> val);
			a = a -> next;
			b = b -> next;
		}
	}
	printf("----------------------------------\n\n");
}







