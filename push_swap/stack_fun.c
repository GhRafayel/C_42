#include "push_swap.h"

t_stack	*create_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> val = num;
	new_node -> position = 0;
	new_node -> next = NULL;
	return (new_node);
}

void	add_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return;
	node -> next = *stack;
	*stack = node;
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*pnt;

	if (!stack || !node)
		return;
	if (!*stack)
	{
		add_front(stack, node);
		return;
	}
	pnt = *stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	pnt->next = node;
	node->next = NULL;
}
