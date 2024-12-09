/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:47:29 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/30 12:47:31 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_valid(t_stack *stack_a, int num)
{
	t_stack	*pnt;

	pnt = stack_a;
	while (pnt)
	{
		if (pnt -> val == num)
		{
			return (1);
		}
		pnt = pnt -> next;
	}
	return (0);
}

int	ft_chac_args(char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-')
			j++;
		while (s[i][j])
		{
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
			{
				printf("error ft_chac_args");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	n;

	n = 2;
	len = stack_size(*stack_a);
	n = len / 5;
	if (len > 250 && len <= 500)
		n = len / 7;
	if (len > 100 && len <= 250)
		n = len / 6;
	if (len < 20)
		n = len / 2;
	while (stack_size(*stack_a) > 1)
	{
		to_stack_b(stack_a, stack_b, found_mite(stack_a, n), n);
	}
	to_stack_a(stack_a, stack_b);
	pa_pb(stack_a, stack_b, 'a');
}

void	to_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 3 && !list_sorted(*stack_a, 'a'))
	{
		while (!list_sorted(*stack_a, 'a'))
		{
			if ((*stack_a)->val > last_node(*stack_a))
				ra_rb(stack_a, 'a');
			else if ((*stack_a)->val > (*stack_a)->next->val)
				sa_sb(stack_a, 'a');
			else
				rra_rrb(stack_a, 'a');
		}
	}
	else if (!list_sorted(*stack_a, 'a'))
		sort(stack_a, stack_b);
}
