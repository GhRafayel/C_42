/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:51:07 by rghazary          #+#    #+#             */
/*   Updated: 2024/11/22 10:51:09 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	les_num(t_stack **stack)
{
	int			big;
	int			temp;
	t_stack		*pnt;

	pnt = (*stack);
	big = pnt->val;
	while (pnt->next)
	{
		temp = pnt->next->val;
		if (temp < big)
		{
			big = temp;
		}
		pnt = pnt->next;
	}
	return (big);
}

int	to_mite(t_stack **stack, int les)
{
	int			num;
	int			tru;
	int			temp;
	t_stack		*pnt;

	pnt = (*stack);
	num = les;
	tru = 1;
	while (pnt->next)
	{
		if (pnt->val > les && tru)
		{
			num = pnt->val;
			tru = 0;
		}
		else if (pnt->val > les)
		{
			temp = pnt->val;
			if (temp < num)
				num = temp;
		}
		pnt = pnt->next;
	}
	return (num);
}

int	fount_biggist(t_stack **stack)
{
	int			num;
	int			i;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt -> val;
	i = 0;
	while (pnt)
	{
		if (pnt->val > num)
		{
			num = pnt->val;
		}
		pnt = pnt->next;
	}
	pnt = (*stack);
	while (pnt)
	{
		if (pnt->val == num)
			break ;
		pnt = pnt->next;
		i++;
	}
	return (i);
}

int	is_biggist(t_stack **stack)
{
	int			num;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt->val;
	while (pnt)
	{
		if (pnt->val > num)
		{
			return (0);
		}
		pnt = pnt->next;
	}
	return (1);
}

int	found_mite(t_stack **stack, int n )
{
	int	mit;
	int	j;

	mit = les_num(stack);
	j = 0;
	while (n > j)
	{
		mit = to_mite(stack, mit);
		j++;
	}
	return (mit);
}
