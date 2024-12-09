#include "push_swap.h"

void	min_on_top(t_stack **stack) 
{
	while ((*stack)->val != find_min(*stack)->val)
	{
		if (find_min(*stack)->position)
			ra_rb(stack, 'a');
		else
			rra_rrb(stack, 'a');
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char ch)
{
	while (*stack != top_node)
	{
		if (ch == 'a')
		{
			if (top_node->position)
				ra_rb(stack, ch);
			else
				rra_rrb(stack, ch);
		}
		else if (ch == 'b')
		{
			if (top_node->position)
				ra_rb(stack, ch);
			else
				rra_rrb(stack, ch);
		}	
	}
}

int	to_mite(t_stack **stack, int les)
{
	int			num;
	int			tru;
	int			temp;
	t_stack		*pnt;
	
	pnt = (*stack);
	num = les;
	tru = 1;
	while (pnt)
	{
		if (pnt -> val > les && tru)
		{
			num = pnt -> val;
			tru = 0;
		}
		else  if (pnt -> val > les)
		{
			temp = pnt -> val;
			if (temp < num)
				num = temp;
		}
		pnt = pnt -> next;
	}
	return (num);
}

int smallest_num(t_stack **stack)
{
	int	big;
	int temp;
	t_stack		*pnt;

	pnt = (*stack);
	big = pnt -> val;
	while (pnt -> next)
	{
		temp = pnt -> next -> val;
		if (temp < big)
		{
			big = temp;
		}
		pnt = pnt -> next;
	}
	return (big);
}

int	find_mite(t_stack **stack, int n )
{
	 int mit;
	 int j;

	 mit = smallest_num(stack);
	 j = 1;
	while (n > j)
	{
		mit = to_mite(stack, mit);
		j++;
	}
	return (mit);
}
