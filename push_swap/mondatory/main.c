/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:22:47 by youssama          #+#    #+#             */
/*   Updated: 2022/04/08 18:01:19 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_stab *va, int c, char **v)
{
	if (c == 1 || c == 5)
		ft_putstr("Error\n");
	if (c != 2 && c != 5)
	{
		free(va->tab_a);
		free(va->tab_b);
		if (v)
			free(v);
	}
	exit (0);
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
		quit(var, 1, v);
	while (v[i])
	{
		n = ft_atoi(v[i], var, v);
		if (n > 2147483647 || n < -2147483648)
			quit(var, 1, v);
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
		quit(0, 5, 0);
	while (v[i])
	{
		tab = ft_strjoin(tab, v[i++]);
		tab = ft_strjoin(tab, "  ");
	}
	tmp = ft_split(tab, ' ');
	i = 0;
	free(tab);
	if (!tmp)
		exit (0);
	while (tmp[i])
		i++;
	*c = i;
	return (tmp);
}

void	nor(t_stab *var)
{
	indexing(var);
	push_sorted_to_b(var);
	push_sorted_to_a(var);
}

int	main(int c, char **v)
{
	t_stab	var;
	char	**tmp;

	tmp = NULL;
	qu(c);
	tmp = parc(v, tmp, &c);
	if (check_arg(tmp) == 0)
		quit(&var, 1, tmp);
	param_to_var(&var, tmp, c++);
	if (check_repeat(var.tab_a, var.top_a) == 0)
		quit(&var, 1, 0);
	if (check_if_sorted(var.tab_a, var.top_a) == 0)
		quit(&var, 0, 0);
	if (c >= 3 && c <= 6)
	{
		if (c <= 4)
			sort_3nb(&var, c);
		if (c > 4)
			sort_5nb(&var, c);
		quit(&var, 0, 0);
	}
	nor(&var);
	quit(&var, 2, tmp);
}
 $>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error