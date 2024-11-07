/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct_rbonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:53:18 by youssama          #+#    #+#             */
/*   Updated: 2022/03/30 22:54:20 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_b(int *t, int top)
{
	int	c;

	c = 0;
	if (top >= 1)
	{
		c = t[top];
		t[top] = t[top - 1];
		t[top - 1] = c;
	}
}

void	sb_b(int *t, int top)
{
	int	c;

	c = 0;
	if (top >= 1)
	{
		c = t[top];
		t[top] = t[top - 1];
		t[top - 1] = c;
	}
}

void	ss_b(int *t_a, int top_a, int *t_b, int top_b)
{
	sa_b(t_a, top_a);
	sb_b(t_b, top_b);
}

void	pb_b(int *t_a, int *top_a, int *t_b, int *top_b)
{
	if (*top_a > -1)
	{
		t_b[*top_b + 1] = t_a[*top_a];
		*top_a -= 1;
		*top_b += 1;
	}
}

void	pa_b(int *t_a, int *top_a, int *t_b, int *top_b)
{
	if (*top_b > -1)
	{
		t_a[*top_a + 1] = t_b[*top_b];
		*top_b -= 1;
		*top_a += 1;
	}
}
