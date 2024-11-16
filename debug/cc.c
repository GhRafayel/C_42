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
int			list_sorted(t_stack *stack, char chr);
int			stack_size(t_stack *stack);
int			last_node(t_stack *stack);
void		add_front(t_stack **stack_a, t_stack *node);
void		add_back(t_stack **stack, t_stack *node);
void		sa_sb(t_stack **stack, char str);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa_pb(t_stack **stack_dest, t_stack **stack_src, char str);
void		ra_rb(t_stack **stack, char str);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra_rrb(t_stack **stack, char str);
void		rrr(t_stack **stack, t_stack **stack_b);
int	        ft_int_valid(t_stack *stack_a, int num);
int	        ft_chac_args(char **s);
int	        ft_atoi(const char *str);
int	        ft_isdigit(int ch);

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
	{
		return (2048);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		num;
	long int	result;
	long int	temp_result;

	num = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			num = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		temp_result = result * 10 + (*str - '0');
		if (num == -1 && -temp_result < -2147483648)
			return (0);
		if (num == 1 && temp_result > 2147483647)
			return (0);
		result = temp_result;
		str++;
	}
	return (result * num);
}
void	sa_sb(t_stack **stack, char str)
{
	int	temp;

	if (*stack)
	{
		temp = (*stack) -> val;
		(*stack) -> val = (*stack) -> next -> val;
		(*stack) -> next -> val = temp;
		if (str == 'a')
			printf("sa\n");
		else if (str == 'b')
			printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_sb(stack_a, 'r');
	sa_sb(stack_b, 'r');
	printf("ss\n");
}

void	pa_pb(t_stack **stack_dest, t_stack **stack_src, char str)
{
	t_stack	*start;
	
	if (*stack_src)
	{
		start = (*stack_src);
		(*stack_src) = start -> next;
		start -> next = (*stack_src);
		add_front(stack_dest, start);
		if (str == 'a')
			printf("pa\n");
		else if (str == 'b')
			printf("pb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a, 'r');
	ra_rb(stack_b, 'r');
	printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a, 'r');
	rra_rrb(stack_b, 'r');
	printf("rrr\n");
}

void	ra_rb(t_stack **stack, char str)
{
	t_stack	*start;

	if (*stack)
	{
		start = (*stack);
		(*stack) = start -> next;
		start -> next = (*stack);
		add_back(stack, start);
		if (str == 'a')
			printf("ra\n");
		else if (str == 'b')
			printf("rb\n");
	}
}

void	rra_rrb(t_stack **stack, char str)
{
	t_stack	*pnt;
	t_stack	*last;

	pnt = *stack;
	if (*stack && (*stack)-> next)
	{
		while (pnt -> next -> next)
		{
			pnt = pnt -> next;
		}
		last = pnt -> next;
		pnt -> next = NULL;
		last -> next = *stack;
		*stack = last;
		if (str == 'a')
			printf("rra\n");
		else if (str == 'b')
			printf("rrb\n");
	}
}

int	list_sorted(t_stack *stack, char chr)
{
	if (!stack)
		return (0);
	t_stack		*pnt;
	int			temp;

	pnt = stack;
	temp = pnt -> val;
	while (pnt -> next)
	{
		if (chr == 'a')
		{
			if (temp > pnt -> next -> val)
				return (0);
		}
		else
		{
			if (temp < pnt -> next -> val)
				return (0);
		}
		pnt = pnt -> next;
		temp = pnt -> val;
	}
	return (1);
}

t_stack	*create_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> val = num;
	new_node -> next = NULL;
	return (new_node);
}

void	add_front(t_stack **stack, t_stack *node)
{
	node -> next = *stack;
	*stack = node;
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*pnt;

	pnt = *stack;
	if (!*stack)
	{
		add_front(stack, node);
		return;
	}
	if (stack && node)
	{
		while (pnt -> next)
		{
			pnt = pnt -> next;
		}
		pnt -> next = node;
		node -> next = NULL;
	}
}

int	stack_size(t_stack *stack)
{
	unsigned int	size;
	// if (!stack)
	// 	return (-1);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}

int	ft_int_valid(t_stack *stack_a, int num)
{
	t_stack	*pnt;

	pnt = stack_a;
	while (pnt)
	{
		if (pnt -> val == num)
		{
			return (1);
		}
		pnt = pnt -> next;
	}
	return (0);
}

int	ft_chac_args(char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-')
			j++;
		while (s[i][j])
		{
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
			{
				printf("error ft_chac_args");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	print_stack(t_stack *stack, char *s)
{
	t_stack	*p;

	p = stack;
	printf("--------------%s-------------\n", s);
	while (p)
	{
		printf("<   %d  >\n", p -> val);
		p = p -> next;
	}
	printf("----------------------------------\n\n");
}

int	last_node(t_stack *stack)
{
	t_stack *pnt;

	pnt = stack;
	while (pnt -> next)
	{
		pnt = pnt -> next;
	}
	return (pnt -> val);
}

void	foo(t_stack **stack_a, t_stack **stack_b, int *i)
{
	if(stack_size(*stack_b) > 1)
	{
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			if ((*stack_b) -> val < last_node(*stack_b))
			{
				rr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				ra_rb(stack_a, 'a');
				*i += 1;
			}
		}
		if ((*stack_a) -> val > (*stack_a) -> next -> val)
		{
			if ((*stack_b) -> val < (*stack_b) -> next -> val && (*stack_b) -> val > last_node(*stack_b))
			{
				ss(stack_a, stack_b);
				*i += 1;
			}
			else 
			{
				sa_sb(stack_a, 'a');
				*i += 1;
			}
		}
		
		if (last_node(*stack_a) < (*stack_a) -> val)
		{
			if (last_node(*stack_b) > (*stack_b) -> val)
			{
				rrr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				rra_rrb(stack_a, 'a');
				*i += 1;
			}
		}
		
		if ((*stack_b) -> val < last_node(*stack_b))
		{
			ra_rb(stack_b, 'b');
				*i += 1;
		}
		if ((*stack_b) -> val < (*stack_b) -> next -> val)
		{
			sa_sb(stack_b, 'b');
			*i += 1;
		}
		if (last_node(*stack_b) > (*stack_b) -> val)
		{
			rra_rrb(stack_a, 'b');
			*i += 1;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");

	while (stack_size(*stack_a) > 2)
	{
		foo(stack_a, stack_b, &i);
		print_stack(*stack_a, "stack_a");
		print_stack(*stack_b, "stack_b");
		
	
		if(stack_size(*stack_b) > 1)
		{
			if ((*stack_a) -> val > last_node(*stack_b) && (*stack_a) -> val < (*stack_b)-> val)
			{
				ra_rb(stack_a, 'a');
				i++;
				while (last_node(*stack_a) < (*stack_b) -> val)
				{

					pa_pb(stack_a, stack_b, 'a');
					i++;
				}
				rra_rrb(stack_a, 'a');
				i++;
			}
			if (list_sorted(*stack_a, 'a') && list_sorted(*stack_b, 'b') && (*stack_a) -> val > (*stack_b) -> val)
			{
				break;
			}
		}
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			ra_rb(stack_a, 'a');
			i++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'b');
			i++;
		}
		print_stack(*stack_a, "stack_a");
		print_stack(*stack_b, "stack_b");
	}
	while (stack_size(*stack_b))
	{
		pa_pb(stack_a, stack_b, 'a');
		i++;
	}
	
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");
	printf(" count %d\n", i);

	/*
	while ( tru)
	{
		foo(stack_a, stack_b, &i);
		while (stack_size(*stack_b) < 2)
		{
			if ((*stack_a) -> val > last_node(*stack_a))
			{
				ra_rb(stack_a, 'a');
				i++;
			}
			else
			{
				pa_pb(stack_b, stack_a, 'b');
				i++;
			}
		}
		if ((*stack_b) -> val < last_node(*stack_b))
		{
			ra_rb(stack_b, 'b');
			i++;
		}
		foo(stack_a, stack_b, &i);
		if ((*stack_a) -> val > last_node(*stack_a))
		{
			ra_rb(stack_a, 'a');
			i++;
		}
		if ((*stack_a) -> val > (*stack_a) -> next -> val)
		{
			sa_sb(stack_a, 'a');
			i++;
		}	
		if ((*stack_a) -> val > last_node(*stack_b) && (*stack_a) -> val < (*stack_b)-> val)
		{
			ra_rb(stack_a, 'a');
			i++;
			while (last_node(*stack_a) < (*stack_b) -> val)
			{
				pa_pb(stack_a, stack_b, 'a');
				i++;
			}
			rra_rrb(stack_a, 'a');
			i++;
		}
		if (list_sorted(*stack_a, 'a'))
		{
			if (stack_size(*stack_b))
			{
				tru = 0;
			}
			while (stack_size(*stack_b))
			{
				i++;
				pa_pb(stack_a, stack_b, 'a');
			}
		}
		else
		{
			i++;
			pa_pb(stack_b, stack_a, 'b');
		}
		foo(stack_a, stack_b, &i);	
	}
	*/

}

void	to_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 3 && !list_sorted(*stack_a, 'a'))
	{
		print_stack(*stack_a, "stack_a");
		while (!list_sorted(*stack_a, 'a'))
		{
			if ((*stack_a) -> val > last_node(*stack_a))
				ra_rb(stack_a, 'a');
			else if ((*stack_a) -> val > (*stack_a) -> next -> val)
				sa_sb(stack_a, 'a');
			else
				rra_rrb(stack_a, 'a');
		}
		print_stack(*stack_a, "stack_a");
	}
	else if (!list_sorted(*stack_a, 'a'))
		sort(stack_a, stack_b);
}

int	main(int nn, char **ss)
{
    (void)nn;
    (void)ss;
    char *s[10] = {"name","1", "9","8", "3", "6", "5", "2", "7"};

	t_stack		*stack_a;
	t_stack		*stack_b;
	int			num;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	i = 1;
	int n = 4;
	if (n > 3 && ft_chac_args(s))
	{
		while (s[i])
		{
			num = ft_atoi(s[i]);
			if (num == 0 && s[i][1] != '\0')
				return (printf("error\n"), 0);
			if (ft_int_valid(stack_a, num))
				return (free(stack_a), free(stack_b), printf("Error\n"), 0);
			add_back (&stack_a, create_new_node(num));
			i++;
		}
		to_sort(&stack_a, &stack_b);
	}
	return (0);
}
