/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:29:05 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/30 13:29:08 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				val;
	int				max;
	int				min;
	int				top;
	int				bot;
	struct s_stack	*next;
}	t_stack;

t_stack		*create_new_node(int num);

void		min_and_max(t_stack *stack);

int			list_sorted(t_stack *stack, char chr);
int			main(int num, char **s);
int			stack_size(t_stack *stack);
int			last_node(t_stack *stack);

void		add_front(t_stack **stack_a, t_stack *node);
void		add_back(t_stack **stack, t_stack *node);

void		sa_sb(t_stack *stack, char *str);
void		ss(t_stack *stack_a, t_stack *stack_b);

void		pa_pb(t_stack **stack_dest, t_stack **stack_src, char *str);

void		ra_rb(t_stack **stack, char *str);
void		rr(t_stack **stack_a, t_stack **stack_b);

void		rra_rrb(t_stack **stack, char *str);