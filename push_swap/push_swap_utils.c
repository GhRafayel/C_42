/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:56 by rghazary          #+#    #+#             */
/*   Updated: 2024/11/12 16:56:57 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_stack *stack, char chr)
{
	if (!stack)
		return (0);
	t_stack		*pnt;
	int			temp;

	pnt = stack;
	temp = pnt -> val;
	while (pnt -> next)
	{
		if (chr == 'a')
		{
			if (temp > pnt -> next -> val)
				return (0);
		}
		else
		{
			if (temp < pnt -> next -> val)
				return (0);
		}
		pnt = pnt -> next;
		temp = pnt -> val;
	}
	return (1);
}

t_stack	*create_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> val = num;
	new_node -> next = NULL;
	return (new_node);
}

void	add_front(t_stack **stack, t_stack *node)
{
	node -> next = *stack;
	*stack = node;
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*pnt;

	pnt = *stack;
	if (!*stack)
	{
		add_front(stack, node);
		return;
	}
	if (stack && node)
	{
		while (pnt -> next)
		{
			pnt = pnt -> next;
		}
		pnt -> next = node;
		node -> next = NULL;
	}
}

int	stack_size(t_stack *stack)
{
	unsigned int	size;
	// if (!stack)
	// 	return (-1);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}