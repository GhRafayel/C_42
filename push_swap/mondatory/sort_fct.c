/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:35:38 by youssama          #+#    #+#             */
/*   Updated: 2022/03/29 22:42:06 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *tab_a, int top_a, char c)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (top_a + 1));
	if (!tmp)
	{
		free(tab_a);
		exit(0);
	}
	tmp[0] = tab_a[top_a];
	if (c != '2')
		ft_putstr("ra\n");
	i = top_a;
	while (i > 0)
	{
		tmp[i] = tab_a[i - 1];
		i--;
	}
	i = 0;
	while (i <= top_a)
	{
		tab_a[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	rb(int *t, int top, char c)
{
	int	*tmp;
	int	i;

	i = top;
	tmp = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(t);
		exit(0);
	}
	tmp[0] = t[top];
	if (c != '2')
		ft_putstr("rb\n");
	while (i > 0)
	{
		tmp[i] = t[i - 1];
		i--;
	}
	i = 0;
	while (i <= top)
	{
		t[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	rr(int *t_a, int top_a, int *t_b, int top_b)
{
	ft_putstr("rr\n");
	ra(t_a, top_a, '2');
	rb(t_b, top_b, '2');
}

void	rra(int *tab, int top, char c)
{
	int	i;
	int	*tmp;

	tmp = malloc (sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(tab);
		exit(0);
	}
	i = top;
	if (c != '2')
		ft_putstr("rra\n");
	while (i > 0)
	{
		tmp[i - 1] = tab[i];
		i--;
	}
	tmp[top] = tab[0];
	i = 0;
	while (i <= top)
	{
		tab[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	rrb(int *tab, int top, char c)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (top + 1));
	if (!tmp)
	{
		free(tab);
		exit(0);
	}
	i = top;
	if (c != '2')
		ft_putstr("rrb\n");
	while (i > 0)
	{
		tmp[i - 1] = tab[i];
		i--;
	}
	tmp[top] = tab[0];
	i = 0;
	while (i <= top)
	{
		tab[i] = tmp[i];
		i++;
	}
	free(tmp);
}
