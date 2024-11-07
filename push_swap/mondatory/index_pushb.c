/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_pushb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:26:02 by youssama          #+#    #+#             */
/*   Updated: 2022/03/29 23:04:55 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stab *var)
{
	int	i_ind;
	int	j_ind;
	int	cnt_ind;
	int	*new_tmp;

	i_ind = -1;
	j_ind = -1;
	cnt_ind = 0;
	new_tmp = (int *)malloc (sizeof(int) * (var->top_a + 1));
	while (++i_ind <= var->top_a)
	{
		j_ind = -1;
		while (++j_ind <= var->top_a)
			if (var->tab_a[j_ind] < var->tab_a[i_ind])
				cnt_ind++;
		new_tmp[i_ind] = cnt_ind;
		cnt_ind = 0;
	}
	free(var->tab_a);
	var->tab_a = new_tmp;
}

void	push_sorted_to_b(t_stab *var)
{
	int	chunk;
	int	n;
	int	counter;

	n = 1;
	counter = 1;
	chunk = (var->top_a / 10) + 10;
	while (var->top_a >= 0)
	{
		if (var->tab_a[var->top_a] < chunk * n)
		{
			pb(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
			if (var->tab_b[var->top_b] < (n * chunk) - (chunk / 2))
				rb(var->tab_b, var->top_b, '1');
			counter++;
		}
		else
		{
			while (var->tab_a[var->top_a] >= chunk * n)
				ra(var->tab_a, var->top_a, '1');
		}
		if (counter == chunk * n)
			n++;
	}
}

void	mini_boucle_sorta(t_stab *var, int *i, int j)
{
	int	find_jj;

	find_jj = -1;
	while (*i <= var->top_b)
	{
		find_jj = find_j(var->tab_b, var->top_b, j);
		if (find_jj >= (var->top_b / 2))
		{
			if (var->tab_b[var->top_b] != j)
				rb(var->tab_b, var->top_b, '1');
		}
		if (find_jj < (var->top_b / 2))
		{
			if (var->tab_b[var->top_b] != j)
				rrb(var->tab_b, var->top_b, '1');
		}
		*i += 1;
	}
}

void	push_sorted_to_a(t_stab *var)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = var->top_b;
	j = var->tab_b[var->top_b];
	while (k + 1)
	{
		i = 0;
		while (i <= var->top_b)
		{
			if (j < var->tab_b[i])
				j = var->tab_b[i];
			i++;
		}
		i = 0;
		mini_boucle_sorta(var, &i, j);
		pa(var->tab_a, &var->top_a, var->tab_b, &var->top_b);
		j = var->tab_b[var->top_b];
		k--;
	}
}
