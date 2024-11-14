/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ruls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:28:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/11/09 15:28:48 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa_sb(t_stack *stack, char *str)
{
	int	temp;

	if (stack)
	{
		temp = stack -> val;
		stack -> val = stack -> next -> val;
		stack -> next -> val = temp;
		ft_printf("%s\n", str);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa_sb(stack_a, "sa");
	sa_sb(stack_b, "sb");
	ft_printf("ss\n");
}

void	pa_pb(t_stack **stack_dest, t_stack **stack_src, char *str)
{
	t_stack	*start;

	if (*stack_src)
	{
		start = *stack_src;
		*stack_src = start -> next;
		start -> next = *stack_src;
		add_front(stack_dest, start);
		ft_printf("%s\n", str);
	}
}

void	ra_rb(t_stack **stack, char *str)
{
	t_stack	*start;

	if (*stack)
	{
		start = *stack;
		*stack = start -> next;
		start -> next = *stack;
		add_back(stack, start);
		ft_printf("%s\n", str);
	}
}

void	rra_rrb(t_stack **stack, char *str)
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
		ft_printf("%s\n", str);
	}
}
