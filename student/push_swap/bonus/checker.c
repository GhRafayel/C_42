#include "checker.h"

void	print_stack(t_stack *stack, t_stack *stack_b)
{
	t_stack	*p;
	t_stack *b;

	p = stack;
	b = stack_b;
	char a = '-';
	printf("stack_a		stack_b\n\n");
	while (p || b)
	{
		if (!p)
		{
			printf("<   %c  >	<   %d  >\n", a, b -> val);
			b = b -> next;
		}
		else if (!b)
		{
			printf("<    %d  >	<   %c  >\n", p -> val, a);
			p = p -> next;
		}
		else
		{
			printf("<   %d  >	<   %d  >\n", p -> val, b -> val);
			p = p -> next;
			b = b -> next;
		}	
	}
	printf("----------------------------------\n\n");
}

void	checker_rr(t_stack **stack_a, t_stack **stack_b)
{
	checker_ra_rb(stack_a);
	checker_ra_rb(stack_b);
}

void	checker_rrr(t_stack **stack_a, t_stack **stack_b)
{
	checker_rra_rrb(stack_a);
	checker_rra_rrb(stack_b);
}

void	checker_sa_sb(t_stack **stack)
{
	int	temp;

	if (*stack)
	{
		temp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = temp;
	}
}

void	checker_ss(t_stack **stack_a, t_stack **stack_b)
{
	checker_sa_sb(stack_a);
	checker_sa_sb(stack_b);
}

void	checker_pa_pb(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*start;
	if (*stack_src)
	{
		start = (*stack_src);
		(*stack_src) = start->next;
		start->next = (*stack_src);
		add_front(stack_dest, start);
	}
}

void	checker_ra_rb(t_stack **stack)
{
	t_stack	*start;

	if (*stack)
	{
		start = (*stack);
		(*stack) = start->next;
		start->next = (*stack);
		add_back(stack, start);
	}
}

void	checker_rra_rrb(t_stack **stack)
{
	t_stack	*pnt;
	t_stack	*last;

	pnt = *stack;
	if (*stack && (*stack)->next)
	{
		while (pnt->next->next)
		{
			pnt = pnt->next;
		}
		last = pnt->next;
		pnt->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

int	ft_cmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	foo(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_cmp(str, "ss\n"))
		checker_ss(stack_a, stack_b);
	else if (ft_cmp(str, "sa\n"))
		checker_sa_sb(stack_a);
	else if (ft_cmp(str, "sb\n"))
		checker_sa_sb(stack_b);
	else if (ft_cmp(str, "rb\n"))
		checker_ra_rb(stack_b);
	else if (ft_cmp(str, "ra\n"))
		checker_ra_rb(stack_a);
	else if (ft_cmp(str, "rr\n"))
		checker_rr(stack_a, stack_b);
	else if (ft_cmp(str, "rra\n"))
		checker_rra_rrb(stack_a);
	else if (ft_cmp(str, "rrb\n"))
		checker_rra_rrb(stack_b);
	else if (ft_cmp(str, "rrr\n"))
		checker_rrr(stack_a, stack_b);
	else if (ft_cmp(str, "pb\n"))
		checker_pa_pb(stack_b, stack_a);
	else if (ft_cmp(str, "pa\n"))
		checker_pa_pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

char	**check_digit(char **str, int tru)
{
	int	i;
	int	j;

	i = 0;
	if (!tru)
		i = 1;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				if (tru)
					return (free_str(str), NULL);
				else
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (str);
}

void	checker_sorting(t_stack **stack_a, t_stack **stack_b)
{
	char	*s;

	s = NULL;
	while (1)
    {
        s = get_next_line(0);
        if (s == NULL)
           break;
		if (!foo(stack_a, stack_b, s))
			break;
		free(s);
    }
	if (list_sorted(stack_a) && !stack_size(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*stack_a);
	free_stack(*stack_b);
}

void	create_stack(t_stack *stack_a, char **str)
{
	int		i;
	int		num;
	t_stack	*stack_b;

	i = 0;
	num = 0;
	stack_b = NULL;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if ((num == 0 && str[i][1] != '\0') || ft_int_valid(stack_a, num))
		{
			free_stack(stack_a);
			write(1, "Error\n", 6);
			return ;
		}
		add_back (&stack_a, create_new_node(num));
		i++;
	}
	checker_sorting(&stack_a, &stack_b);
}

char	**ft_check_args(char **s, int n, char **str)
{
	if (n == 2 && s[1][0])
	{
		str = ft_split(s[1], ' ');
		str = check_digit(str, 1);
	}
	else if (s[1][0])
	{
		str = check_digit(s, 0);
		if (str)
			str++;
	}
	return (str);
}

int	main(int n, char **s)
{
	t_stack		*stack_a;
	char		**str;

	stack_a = NULL;
	str = NULL;
	if (n > 1)
		str = ft_check_args(s, n, str);
	if (str && str[0])
	{
		create_stack(stack_a, str);
		if (n == 2)
			free_str(str);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}