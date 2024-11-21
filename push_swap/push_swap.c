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
/*
void	foo(t_stack **stack_a, t_stack **stack_b, int *i)
{
	if(stack_size(*stack_b) > 1)
	{
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			if ((*stack_b) -> val < last_node(*stack_b))
			{
				rr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				ra_rb(stack_a, 'a');
				*i += 1;
			}
		}
		if ((*stack_b) -> val < last_node(*stack_b))
		{
			ra_rb(stack_a, 'b');
				*i += 1;
		}
		if (last_node(*stack_a) < (*stack_a) -> val)
		{
			if (last_node(*stack_b) > (*stack_b) -> val)
			{
				rrr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				rra_rrb(stack_a, 'a');
				*i += 1;
			}
		}
		if (last_node(*stack_b) > (*stack_b) -> val)
		{
			rra_rrb(stack_a, 'b');
			*i += 1;
		}
		if ((*stack_a) -> val > (*stack_a) -> next -> val)
		{
			if ((*stack_b) -> val < (*stack_b) -> next -> val)
			{
				ss(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				sa_sb(stack_a, 'a');
				*i += 1;
			}
		}
		if ((*stack_b) -> val < (*stack_b) -> next -> val)
		{
			sa_sb(stack_b, 'b');
			*i += 1;
		}
	}
}
*/

void	foo(t_stack **stack_a, t_stack **stack_b, int *i)
{
	if(stack_size(*stack_b) > 1)
	{
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			if ((*stack_b) -> val < last_node(*stack_b))
			{
				rr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				ra_rb(stack_a, 'a');
				*i += 1;
			}
		}
		if ((*stack_a) -> val > (*stack_a) -> next -> val)
		{
			if ((*stack_b) -> val < (*stack_b) -> next -> val && (*stack_b) -> val > last_node(*stack_b))
			{
				ss(stack_a, stack_b);
				*i += 1;
			}
			else 
			{
				sa_sb(stack_a, 'a');
				*i += 1;
			}
		}
		
		if (last_node(*stack_a) < (*stack_a) -> val)
		{
			if (last_node(*stack_b) > (*stack_b) -> val)
			{
				rrr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				rra_rrb(stack_a, 'a');
				*i += 1;
			}
		}
		
		if ((*stack_b) -> val < last_node(*stack_b))
		{
			ra_rb(stack_b, 'b');
				*i += 1;
		}
		if ((*stack_b) -> val < (*stack_b) -> next -> val)
		{
			sa_sb(stack_b, 'b');
			*i += 1;
		}
		if (last_node(*stack_b) > (*stack_b) -> val)
		{
			rra_rrb(stack_a, 'b');
			*i += 1;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	
	while (stack_size(*stack_a) > 2)
	{
		foo(stack_a, stack_b, &i);
		if(stack_size(*stack_b) > 1)
		{
			if ((*stack_a) -> val > last_node(*stack_b) && (*stack_a) -> val < (*stack_b)-> val)
			{
				ra_rb(stack_a, 'a');
				i++;
				while (last_node(*stack_a) < (*stack_b) -> val)
				{
					pa_pb(stack_a, stack_b, 'a');
					i++;
				}
				rra_rrb(stack_a, 'a');
				i++;
			}
			if (list_sorted(*stack_a, 'a') && list_sorted(*stack_b, 'b') && (*stack_a) -> val > (*stack_b) -> val)
			{
				break;
			}
		}
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			ra_rb(stack_a, 'a');
			i++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'b');
			i++;
		}
	}
	while (stack_size(*stack_b))
	{
		pa_pb(stack_a, stack_b, 'a');
		i++;
	}
	
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");
	printf(" count %d\n", i);
}


/*
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");

	while (stack_size(*stack_a) > 3)
	{
		foo(stack_a, stack_b, &i);
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			ra_rb(stack_a, 'a');
			i++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'b');
			i++;
		}
	}
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");
	printf(" count %d\n", i);

	
}

*/
void	to_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 3 && !list_sorted(*stack_a, 'a'))
	{
		print_stack(*stack_a, "stack_a");
		while (!list_sorted(*stack_a, 'a'))
		{
			if ((*stack_a) -> val > last_node(*stack_a))
				ra_rb(stack_a, 'a');
			else if ((*stack_a) -> val > (*stack_a) -> next -> val)
				sa_sb(stack_a, 'a');
			else
				rra_rrb(stack_a, 'a');
		}
		print_stack(*stack_a, "stack_a");
	}
	else if (!list_sorted(*stack_a, 'a'))
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
		to_sort(&stack_a, &stack_b);
	}
	return (0);
}
