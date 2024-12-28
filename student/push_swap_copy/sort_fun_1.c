/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:31:39 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:31:42 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack			*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	long			min;
	t_stack			*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	last_node(t_stack **stack)
{
	t_stack	*pnt;

	pnt = *stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	return (pnt->val);
}

void	sort_three(t_stack **stack_a)
{
	int			biggest;
	t_stack		*s;

	s = *stack_a;
	biggest = s->val;
	while (s)
	{
		if (biggest < s->val)
			biggest = s->val;
		s = s->next;
	}
	if (biggest == (*stack_a)->val)
		ra_rb(stack_a, 'a');
	else if ((*stack_a)->next->val == biggest)
		rra_rrb(stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa_sb(stack_a, 'a');
}
