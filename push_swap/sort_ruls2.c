/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ruls2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:51:57 by rghazary          #+#    #+#             */
/*   Updated: 2024/11/11 16:52:01 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a, 'r');
	ra_rb(stack_b, 'r');
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a, 'r');
	rra_rrb(stack_b, 'r');
	ft_printf("rrr\n");
}

void	min_and_max(t_stack *stack)
{
	t_stack	*pnt;
	int		max;
	int		min;

	pnt = stack;
	max = pnt -> val;
	min = pnt -> val;
	while (pnt)
	{
		if (pnt -> val > max)
			max = pnt -> val;
		else if (pnt -> val < min)
			min = pnt -> val;
		pnt = pnt -> next;
	}
	pnt = stack;
	while (pnt)
	{
		pnt -> max = max;
		pnt -> min = min;
		pnt = pnt -> next;
	}
}

int	last_node(t_stack *stack)
{
	t_stack *pnt;

	pnt = stack;
	while (pnt -> next)
	{
		pnt = pnt -> next;
	}
	return (pnt -> val);
}