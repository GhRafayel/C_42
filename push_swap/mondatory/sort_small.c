/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:50:45 by youssama          #+#    #+#             */
/*   Updated: 2022/03/29 22:54:01 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3nb(t_stab *var, int c)
{
	if (c == 3)
	{
		if (check_if_sorted(var->tab_a, var->top_a) != 0)
			sa(var->tab_a, var->top_a, '1');
		return ;
	}
	while (check_if_sorted(var->tab_a, var->top_a) != 0)
	{
		if (var->tab_a[var->top_a] > var->tab_a[(var->top_a) - 1])
		{
			sa(var->tab_a, var->top_a, '1');
			if (check_if_sorted(var->tab_a, var->top_a) != 0)
				rra(var->tab_a, var->top_a, '1');
		}
		else
			rra(var->tab_a, var->top_a, '1');
	}
}

int	find_small(int *t, int top)
{
	int	i;
	int	j;

	i = top;
	j = t[top];
	while (i >= 0)
	{
		if (j > t[i])
			j = t[i];
		i--;
	}
	return (j);
}

int	find_i(int *t, int top, int find)
{
	int	i;

	i = top;
	while (i >= 0)
	{
		if (t[i] == find)
			return (i);
		i--;
	}
	return (-1);
}

void	push_to_b(t_stab *var)
{
	int	j;

	j = find_i(var->tab_a, var->top_a, find_small(var->tab_a, var->top_a));
	if (j == var->top_a)
	{
		pb(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
		return ;
	}
	if (j < var->top_a / 2)
		while (var->tab_a[var->top_a] != find_small(var->tab_a, var->top_a))
			rra(var->tab_a, var->top_a, '1');
	else
		while (var->tab_a[var->top_a] != find_small(var->tab_a, var->top_a))
			ra(var->tab_a, var->top_a, '1');
	pb(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
}

void	sort_5nb(t_stab *var, int c)
{
	push_to_b(var);
	if (c == 6)
		push_to_b(var);
	sort_3nb(var, 4);
	pa(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
	if (c == 6)
		pa(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
}
