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

int	last_node(t_stack *stack)
{
	t_stack	*pnt;

	pnt = stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	return (pnt->val);
}

void	found_doub_op_1(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_b) > 1 && stack_size(*stack_a) > 1)
	{
		if ((*stack_b)->val < (*stack_b)->next->val)
		{
			if ((*stack_a)->val > (*stack_a)->next->val)
			{
				ss(stack_a, stack_b);
			}
			else
			{
				sa_sb(stack_b, 'b');
			}
		}
		else if ((*stack_a)->val > (*stack_a)->next->val)
		{
			sa_sb(stack_a, 'a');
		}
	}
}

void	found_doub_op_2(t_stack **stack_a, t_stack **stack_b, int center)
{
	if (stack_size(*stack_a) > 2 && stack_size(*stack_b) > 2)
	{
		if (rang((*stack_b)->val, (*stack_b)->next->val)
			> rang((*stack_b)->val, last_node(*stack_b)))
		{
			if (rang((*stack_a)->val, (*stack_a)->next->val)
				> rang((*stack_a)->val, last_node(*stack_a))
				&& (*stack_a)->val > center)
			{
				rr(stack_a, stack_b);
			}
			else
			{
				ra_rb(stack_b, 'b');
			}
		}
		else if ((rang((*stack_a)->val, (*stack_a)->next->val)
				> rang((*stack_a)->val, last_node(*stack_a)))
			&& (*stack_a)->val > center)
		{
			ra_rb(stack_a, 'a');
		}
	}
}
