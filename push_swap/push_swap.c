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

void	print_stack(t_stack *stack, char *s)
{
	t_stack	*p;

	p = stack;
	printf("--------------%s-------------\n", s);
	while (p)
	{
		printf("<   %d  >\n", p -> val);
		p = p -> next;
	}
	printf("----------------------------------\n\n");
}

int	find_big(t_stack *stack, char *str, int *i)
{
	if (stack -> val > last_node(stack))
	{
		ra_rb(&stack, str);
		*i += 1;
		return (1);
	}
	return (0);
}
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i = 0;

	print_stack(stack_a, "stack_a");
	print_stack(stack_b, "stack_b");

	while(stack_size(stack_a) != 1)
	{
		if (stack_size(stack_b) >= 2 && !find_big(stack_a, "ra", &i))
		{
			if (stack_a -> val > last_node(stack_a))
			{
				if (stack_b -> val < last_node(stack_b))
				{
					rr(stack_a, "rr");
					i++;
				}
				ra_rb(stack_a, "ra");
			}
			else
			{
				if (stack_a -> val < stack_a -> next -> val)
				{
					ra_rb(&stack_b, "rb");
					i++;
				}
			}
		}
		else if (stack_size(stack_b) < 2)
		{
			if (!find_big(stack_a, "ra", &i))
			{
				pa_pb(&stack_b, &stack_a, "pb");
				i++;
			}
		}
	}
	while (stack_size(stack_b) != 0)
	{
		pa_pb(&stack_a, &stack_b, "pa");
		i++;
	}
	print_stack(stack_a, "stack_a");
	print_stack(stack_b, "stack_b");
	printf("===%d===\n",i);
}

void	to_sort(t_stack *stack_a, t_stack *stack_b)
{
		if (stack_size(stack_a) == 3 && !list_sorted(stack_a, 'a'))
		{
			while (!list_sorted(stack_a, 'a'))
			{
				if (stack_a -> val > last_node(stack_a))
					ra_rb(&stack_a, "ra");
				else if (stack_a -> val > stack_a -> next -> val)
					sa_sb(stack_a, "sa");
				else
					rra_rrb(&stack_a, "rra");
			}
		}
		else
			sort(stack_a, stack_b);
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
		min_and_max(stack_a);
		to_sort(stack_a, stack_b);
	}
	return (0);
}
