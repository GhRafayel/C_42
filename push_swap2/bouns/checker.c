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

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
}

void	sa_sb(t_stack **stack)
{
	int	temp;

	if (*stack)
	{
		temp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = temp;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
}

void	pa_pb(t_stack **stack_dest, t_stack **stack_src)
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

void	ra_rb(t_stack **stack)
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

void	rra_rrb(t_stack **stack)
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

ssize_t	ft_str_chr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*fft_strdup(char **dest, char **src)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(*src);
	*dest = (char *)malloc((count + 1) * sizeof(char));
	if (*dest != NULL)
	{
		while ((*src)[i] != '\0')
		{
			(*dest)[i] = (*src)[i];
			i++;
		}
		(*dest)[i] = '\0';
	}
	free(*src);
	*src = NULL;
	return (*dest);
}

char	*fft_str_join(char **str1, char **str2, ssize_t *count)
{
	char	*temp;
	size_t	len;
	size_t	i;
	size_t	j;

	temp = NULL;
	if (ft_str_chr(*str2) >= 0)
		*count = 0;
	if (*str1 == NULL)
		return (fft_strdup(&*str1, &*str2));
	len = ft_strlen(*str1) + ft_strlen(*str2) + 1;
	temp = (char *)malloc(len * sizeof(char));
	if (temp == NULL)
		return (free(*str1), *str1 = NULL, free(*str2), str2 = NULL, NULL);
	i = -1;
	while ((*str1)[++i])
		temp[i] = (*str1)[i];
	j = -1;
	free(*str1);
	*str1 = NULL;
	while ((*str2)[++j])
		temp[i + j] = (*str2)[j];
	temp[j + i] = '\0';
	return (free(*str2), *str2 = NULL, fft_strdup(&*str1, &temp));
}

char	*fft_sub_str(char **dest, char **src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL || !*src)
	{
		return (NULL);
	}
	*dest = (char *)malloc((len - start + 1) * sizeof(char));
	if (*dest == NULL)
	{
		return (NULL);
	}
	while ((*src)[i + start] && i < len)
	{
		(*dest)[i] = (*src)[start + i];
		i++;
	}
	(*dest)[i] = '\0';
	return (*dest);
}

char	*ft_control(char **static_str)
{
	ssize_t	i;
	char	*str;
	char	*res;

	i = 0;
	if (*static_str != NULL)
	{
		if ((*static_str)[0] == '\0')
			return (free(*static_str), *static_str = NULL);
		i = ft_str_chr(*static_str);
		if (i < 0)
			return (fft_strdup(&res, static_str), res);
		str = fft_sub_str(&str, &*static_str, i + 1, ft_strlen(*static_str));
		if (str == NULL)
			return (free(*static_str),*static_str = NULL);
		res = fft_sub_str(&res, static_str, 0, i + 1);
		if (res == NULL)
			return (free(str), free(*static_str), *static_str = NULL);
		free(*static_str);
		*static_str = NULL;
		*static_str = str;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*static_str;
	char			*str_readed;
	ssize_t			count;
	
	count = 1;
	if (fd < 0 || fd > 1024)
		return (NULL);
	while (count)
	{
		str_readed = (char *)malloc((5 + 1) * sizeof(char));
		if (str_readed == NULL)
			return (free(static_str), static_str = NULL, NULL);
		count = read(fd, str_readed, 5);
		if (count < 0)
			return (free(str_readed), free(static_str), static_str = NULL);
		if (count > 0)
		{
			str_readed[count] = '\0';
			fft_str_join(&static_str, &str_readed, &count);
		}
		else
			free(str_readed);
	}
	return (ft_control(&static_str));
}

int	list_sorted(t_stack *stack, char chr)
{
	t_stack		*pnt;
	int			temp;

	if (!stack)
		return (0);
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
		return ;
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

void	foo(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "ss", 2))
		ss(stack_a, stack_b);
	else if (ft_strncmp(str, "sa", 2))
		sa_sb(stack_a);
	else if (ft_strncmp(str, "sb", 2))
		sa_sb(stack_b);
	else if (ft_strncmp(str, "rb", 2))
		ra_rb(stack_a);
	else if (ft_strncmp(str, "ra", 2))
		ra_rb(stack_b);
	else if (ft_strncmp(str, "rr", 2))
		rr(stack_a, stack_b);
	else if (ft_strncmp(str, "rra", 3))
		rra_rrb(stack_a);
	else if (ft_strncmp(str, "rrb", 3))
		rra_rrb(stack_b);
	else if (ft_strncmp(str, "rrr", 3))
		rrr(stack_a, stack_b);
	else if (ft_strncmp(str, "pb", 2))
		pa_pb(stack_b, stack_a);
	else if (ft_strncmp(str, "pa", 2))
		pa_pb(stack_a, stack_b);
}

int	main(int n, char **s)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*str;
	int			num;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	i = 1;
	if (n > 3 && ft_chac_args(s))
	{
		while (s[i])
		{
			num = ft_atoi(s[i]);
			if (num == 0 && s[i][1] != '\0')
				return (write(1, "Error\n", 6), 0);
			if (ft_int_valid(stack_a, num))
				return (free(stack_a), free(stack_b), write(1, "Error\n", 6), 0);
			add_back (&stack_a, create_new_node(num));
			i++;
		}
		i = 1;
		str = NULL;
		//print_stack(stack_a, stack_b);
		while (i)
		{
			str = get_next_line(0);
			if (!str)
				i = 0;
			else
			{
				printf("%s", str);
				foo(&stack_a, &stack_b, str);
				print_stack(stack_a, stack_b);
				free(str);
			}
			
		}
		//print_stack(stack_a, stack_b);
	}
	return (0);
}