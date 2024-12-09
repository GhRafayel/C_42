#include "push_swap.h"

int	list_sorted(t_stack **stack)
{
	if (!stack)
		return (0);
	t_stack		*pnt;
	int			temp;

	pnt = *stack;
	temp = pnt->val;
	while (pnt->next)
	{
		if (temp > pnt->next->val)
			return (0);
		pnt = pnt->next;
		temp = pnt->val;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	unsigned int	size;
	t_stack			*pnt;

	size = 0;
	pnt = stack;
	while (pnt)
	{
		size++;
		pnt = pnt->next;
	}
	return (size);
}
