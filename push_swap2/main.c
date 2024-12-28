/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:03:06 by rghazary          #+#    #+#             */
/*   Updated: 2024/11/22 11:03:08 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rang(int a, int b)
{
	int	res;

	res = a - b;
	if (res < 0)
		res *= -1;
	return (res - 1);
}

void	to_stack_b(t_stack **stack_a, t_stack **stack_b, int center, int n)
{
	while (n && stack_size(*stack_a) > 1)
	{
		found_doub_op_2(stack_a, stack_b, center);
		found_doub_op_1(stack_a, stack_b);
		if ((*stack_a)->val <= center)
		{
			pa_pb(stack_b, stack_a, 'b');
			n--;
		}
		else
			ra_rb(stack_a, 'a');
	}
}

void	to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	s_len;

	s_len = stack_size(*stack_b);
	while (s_len > 1)
	{

		if (!is_biggist(stack_b))
		{
			if (fount_biggist(stack_b) > stack_size(*stack_b) / 2)
				rra_rrb(stack_b, 'b');
			else
				ra_rb(stack_b, 'b');
		}
		else
		{
			pa_pb(stack_a, stack_b, 'a');
			s_len--;
		}
	}
}

int	main(int n, char **s)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			num;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	i = 1;
	if (n > 3 && ft_chac_args(s))
	{
		while (s[i])
		{
			num = ft_atoi(s[i]);
			if (num == 0 && s[i][1] != '\0')
				return (printf("error\n"), 0);
			if (ft_int_valid(stack_a, num))
				return (free(stack_a), free(stack_b), printf("Error\n"), 0);
			add_back (&stack_a, create_new_node(num));
			i++;
		}
		to_sort(&stack_a, &stack_b);
	}
	return (0);
}
