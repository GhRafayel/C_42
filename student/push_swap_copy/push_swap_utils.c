/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:31:26 by rghazary          #+#    #+#             */
/*   Updated: 2024/12/09 11:31:31 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_stack **stack)
{
	t_stack		*pnt;
	int			temp;

	if (!stack)
		return (0);
	pnt = *stack;
	temp = pnt->val;
	while (pnt->next)
	{
		if (temp > pnt->next->val)
			return (0);
		pnt = pnt->next;
		temp = pnt->val;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	unsigned int	size;
	t_stack			*pnt;

	size = 0;
	pnt = stack;
	while (pnt)
	{
		size++;
		pnt = pnt->next;
	}
	return (size);
}

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

void	free_stack(t_stack *stack)
{
	t_stack	*next_node;

	while (stack != NULL)
	{
		next_node = stack->next;
		free(stack);
		stack = next_node;
	}
	stack = NULL;
}

void	*free_str(char **result)
{
	char	**temp;

	temp = result;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(result);
	return (NULL);
}
