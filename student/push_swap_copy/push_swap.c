/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:31:06 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:31:09 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_stack_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*che_node;

	che_node = get_cheapest(*stack_b);
	if (che_node->position && che_node->target_node->position)
	{
		find_rr(stack_b, stack_a, che_node);
	}
	else if (!(che_node->position) && !(che_node->target_node->position))
	{
		find_rrr(stack_b, stack_a, che_node);
	}
	prep_for_push(stack_b, che_node, 'b');
	prep_for_push(stack_a, che_node->target_node, 'a');
	pa_pb(stack_a, stack_b, 'a');
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	mit;

	len = stack_size(*stack_a);
	mit = find_mite(stack_a, len / 2);
	pa_pb(stack_b, stack_a, 'b');
	while (len > 3 && !list_sorted(stack_a))
	{
		pa_pb(stack_b, stack_a, 'b');
		len--;
		if ((*stack_b)->val < mit)
			ra_rb(stack_b, 'b');
	}
	len = stack_size(*stack_b);
	while (len-- > 0)
	{
		put_indexs(*stack_a);
		put_indexs(*stack_b);
		find_target(*stack_b, *stack_a);
		nodes_cost(*stack_b, *stack_a);
		set_cheapest(*stack_b);
		to_stack_a(stack_b, stack_a);
	}
	put_indexs(*stack_a);
	min_on_top(stack_a);
}
