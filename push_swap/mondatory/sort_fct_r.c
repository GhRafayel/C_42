/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:42:33 by youssama          #+#    #+#             */
/*   Updated: 2022/03/29 22:45:37 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *t, int top, char cn)
{
	int	c;

	c = 0;
	if (cn != '2')
		ft_putstr("sa\n");
	if (top >= 1)
	{
		c = t[top];
		t[top] = t[top - 1];
		t[top - 1] = c;
	}
}

void	sb(int *t, int top, char cn)
{
	int	c;

	c = 0;
	if (cn != '2')
		ft_putstr("sb\n");
	if (top >= 1)
	{
		c = t[top];
		t[top] = t[top - 1];
		t[top - 1] = c;
	}
}

void	ss(int *t_a, int top_a, int *t_b, int top_b)
{
	ft_putstr("ss\n");
	sa(t_a, top_a, '2');
	sb(t_b, top_b, '2');
}

void	pb(int *t_a, int *top_a, int *t_b, int *top_b)
{
	ft_putstr("pb\n");
	if (*top_a > -1)
	{
		t_b[*top_b + 1] = t_a[*top_a];
		*top_a -= 1;
		*top_b += 1;
	}
}

void	pa(int *t_a, int *top_a, int *t_b, int *top_b)
{
	ft_putstr("pa\n");
	if (*top_b > -1)
	{
		t_a[*top_a + 1] = t_b[*top_b];
		*top_b -= 1;
		*top_a += 1;
	}
}
