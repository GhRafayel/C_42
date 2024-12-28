/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ruls_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:32:14 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:32:16 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack **stack, char str)
{
	t_stack	*start;

	if (*stack)
	{
		start = (*stack);
		(*stack) = start -> next;
		start -> next = (*stack);
		add_back(stack, start);
		if (str == 'a')
			write(1, "ra\n", 3);
		else if (str == 'b')
			write(1, "rb\n", 3);
	}
}

void	rra_rrb(t_stack **stack, char str)
{
	t_stack	*pnt;
	t_stack	*last;

	pnt = *stack;
	if (*stack && (*stack)-> next)
	{
		while (pnt -> next -> next)
		{
			pnt = pnt -> next;
		}
		last = pnt -> next;
		pnt -> next = NULL;
		last -> next = *stack;
		*stack = last;
		if (str == 'a')
			write(1, "rra\n", 4);
		else if (str == 'b')
			write(1, "rrb\n", 4);
	}
}

void	find_rr(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	put_indexs(*a);
	put_indexs(*b);
}

void	find_rrr(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	put_indexs(*a);
	put_indexs(*b);
}
