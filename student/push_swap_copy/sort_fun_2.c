/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:31:49 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:31:51 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_indexs(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->position = 1;
		else
			stack->position = 0;
		stack = stack->next;
		++i;
	}
}

void	find_target(t_stack *b, t_stack *a)
{
	t_stack		*current_a;
	t_stack		*target_node;
	int			best_match_index;

	while (b)
	{
		best_match_index = INT_MIN;
		current_a = a;
		while (current_a)
		{
			if (current_a->val < b->val && current_a->val > best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MIN)
			b->target_node = find_max(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack		*current_a;
	t_stack		*target_node;
	int			best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val
				&& current_a->val < best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	nodes_cost(t_stack *stack_b, t_stack *stack_a)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->index;
		if (!(stack_b->position))
			stack_b->cost = len_b - (stack_b->index);
		if (stack_b->target_node->position)
			stack_b->cost += stack_b->target_node->index;
		else
			stack_b->cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack			*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
