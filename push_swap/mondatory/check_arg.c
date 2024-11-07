/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:56:04 by youssama          #+#    #+#             */
/*   Updated: 2022/04/08 18:01:09 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **v)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!v || !*v)
		return (0);
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (j == 0 && (v[i][j] == '-' || v[i][j] == '+'))
				j++;
			if ((v[i][j] < '0' || v[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_repeat(int *t, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (t[i] == t[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_space(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] == ' ' && j == 0)
				return (0);
			if (v[i][j] == ' ' && (v[i][j + 1] == '\0' || v[i][j + 1] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
