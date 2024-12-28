/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:30:32 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:30:42 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_digit(char **str, int tru)
{
	int	i;
	int	j;

	i = 0;
	if (!tru)
		i = 1;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				if (tru)
					return (free_str(str), NULL);
				else
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (str);
}

void	to_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!list_sorted(&stack_a))
	{
		if (stack_size(stack_a) == 2)
		{
			if (stack_a->val > stack_a->next->val)
				sa_sb(&stack_a, 'a');
		}
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

void	create_stack(t_stack *stack_a, char **str)
{
	int		i;
	int		num;
	t_stack	*stack_b;

	i = 0;
	num = 0;
	stack_b = NULL;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if ((num == 0 && str[i][1] != '\0') || ft_int_valid(stack_a, num))
		{
			free_stack(stack_a);
			write(1, "Error\n", 6);
			return ;
		}
		add_back (&stack_a, create_new_node(num));
		i++;
	}
	to_sort(stack_a, stack_b);
}

char	**ft_check_args(char **s, int n, char **str)
{
	if (n == 2 && s[1][0])
	{
		str = ft_split(s[1], ' ');
		str = check_digit(str, 1);
	}
	else if (s[1][0])
	{
		str = check_digit(s, 0);
		if (str)
			str++;
	}
	return (str);
}

int	main(int n, char **s)
{
	t_stack		*stack_a;
	char		**str;

	stack_a = NULL;
	str = NULL;
	if (n > 1)
		str = ft_check_args(s, n, str);
	if (str && str[0])
	{
		create_stack(stack_a, str);
		if (n == 2)
			free_str(str);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
