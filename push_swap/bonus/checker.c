/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:40:03 by youssama          #+#    #+#             */
/*   Updated: 2022/04/13 23:08:32 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	quit_b(t_stab *va, int c, char **v, char *j)
{
	if (c == 1 || c == 3)
		ft_putstr("Error\n");
	if (c == 1 || c == 2)
	{
		free(va->tab_a);
		free(va->tab_b);
	}
	if (v)
		fret(v);
	if (j)
		free(j);
	exit (0);
}

void	test_j(char *j, t_stab *va, char **v)
{
	if (ft_strcmp(j, "ra\n") == 0)
		ra_b(va->tab_a, va->top_a);
	else if (ft_strcmp(j, "rb\n") == 0)
		rb_b(va->tab_b, va->top_b);
	else if (ft_strcmp(j, "rr\n") == 0)
		rr_b(va->tab_a, va->top_a, va->tab_b, va->top_b);
	else if (ft_strcmp(j, "sa\n") == 0)
		sa_b(va->tab_a, va->top_a);
	else if (ft_strcmp(j, "sb\n") == 0)
		sb_b(va->tab_b, va->top_b);
	else if (ft_strcmp(j, "ss\n") == 0)
		ss_b(va->tab_a, va->top_a, va->tab_b, va->top_b);
	else if (ft_strcmp(j, "rra\n") == 0)
		rra_b(va->tab_a, va->top_a);
	else if (ft_strcmp(j, "rrb\n") == 0)
		rrb_b(va->tab_b, va->top_b);
	else if (ft_strcmp(j, "rrr\n") == 0)
		rrr_b(va->tab_a, va->top_a, va->tab_b, va->top_b);
	else if (ft_strcmp(j, "pa\n") == 0)
		pa_b(va->tab_a, &va->top_a, va->tab_b, &va->top_b);
	else if (ft_strcmp(j, "pb\n") == 0)
		pb_b(va->tab_a, &va->top_a, va->tab_b, &va->top_b);
	else
		quit_b(va, 1, v, j);
	free(j);
}

void	param_to_var(t_stab *var, char **v, int c)
{
	long long	n;
	int			i;

	i = 0;
	var->top_b = -1;
	var->tab_a = (int *)malloc(sizeof(int) * c);
	var->tab_b = (int *)malloc(sizeof(int) * c);
	if (!var->tab_a || !var->tab_b)
		quit_b(var, 1, v, 0);
	while (v[i])
	{
		n = ft_atoi(v[i], var, v);
		if (n > 2147483647 || n < -2147483648)
			quit_b(var, 1, v, 0);
		var->tab_a[c - i - 1] = (int)n;
		i++;
	}
	var->top_a = i - 1;
}

char	**parc(char **v, char **tmp, int *c)
{
	int		i;
	char	*tab;

	tab = NULL;
	i = 1;
	if (check_space(v) == 0)
		quit_b(0, 3, 0, 0);
	while (v[i])
	{
		tab = ft_strjoin(tab, v[i++]);
		tab = ft_strjoin(tab, "  ");
	}
	tmp = ft_split(tab, ' ', tmp);
	i = 0;
	free(tab);
	if (!tmp)
		exit(0);
	while (tmp[i])
		i++;
	*c = i;
	return (tmp);
}

int	main(int c, char **v)
{
	char	*j;
	t_stab	va;
	char	**tmp;

	if (c <= 1)
		return (0);
	tmp = NULL;
	tmp = parc(v, tmp, &c);
	if (check_arg(tmp) == 0)
		quit_b(&va, 3, tmp, 0);
	param_to_var(&va, tmp, c);
	if (check_repeat(va.tab_a, va.top_a) == 0)
		quit_b(&va, 1, tmp, 0);
	j = get_next_line(0);
	while (j != NULL)
	{
		test_j(j, &va, tmp);
		j = get_next_line(0);
	}
	if (check(va.tab_a, va.top_a) == 0 && va.top_b == -1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	quit_b(&va, 2, tmp, j);
}
