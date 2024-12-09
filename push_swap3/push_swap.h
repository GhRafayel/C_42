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
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack		*create_new_node(int num);

int			ft_chac_args(char **s);
int			list_sorted(t_stack *stack, char chr);
int			stack_size(t_stack *stack);
int			last_node(t_stack *stack);
int			rang(int a, int b);
int			to_mite(t_stack **stack, int les);
int			fount_biggist(t_stack **stack);
int			is_biggist(t_stack **stack);
int			les_num(t_stack **stack);
int			found_mite(t_stack **stack, int n);
int			ft_int_valid(t_stack *stack_a, int num);
void		to_stack_a(t_stack **stack_a, t_stack **stack_b);
void		to_stack_b(t_stack **stack_a, t_stack **stack_b, int center, int n);

void		found_doub_op_1(t_stack **stack_a, t_stack **stack_b);
void		found_doub_op_2(t_stack **stack_a, t_stack **stack_b, int center);

void		add_front(t_stack **stack_a, t_stack *node);
void		add_back(t_stack **stack, t_stack *node);

void		to_sort(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);

void		sa_sb(t_stack **stack, char str);
void		ss(t_stack **stack_a, t_stack **stack_b);

void		pa_pb(t_stack **stack_dest, t_stack **stack_src, char str);

void		ra_rb(t_stack **stack, char str);
void		rr(t_stack **stack_a, t_stack **stack_b);

void		rra_rrb(t_stack **stack, char str);
void		rrr(t_stack **stack, t_stack **stack_b);