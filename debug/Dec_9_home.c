#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <limits.h> 


typedef struct s_stack
{
	int				val;
	int				index;
	int				position;
	int				cost;
	int 			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

t_stack		*create_new_node(int num);
int			list_sorted(t_stack **stack);
int			stack_size(t_stack *stack);
int			last_node(t_stack **stack);
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
int	        ft_atoi(const char *str);
int	        ft_isdigit(int ch);
void	print_stack(t_stack *stack, t_stack *stack_b);
void	sort_three(t_stack **stack_a);


void free_stack(t_stack *stack)
{
    t_stack *current = stack;
    t_stack *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        current->target_node = NULL;
        free(current);
        current = next_node;
    }
}

void *free_str(char **result)
{
    char **temp = result;

    while (*temp) 
    {
        free(*temp);
        temp++;
    }
    free(result);
    return NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_substr(const char *s, unsigned start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	size_t			s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
		return ("");
	if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[i + start] && len)
	{
		new_str[i] = s[i + start];
		i++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}

static size_t	how_many_words(const char *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static void	*ft_free(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[--i]);
	}
	free(result);
	return (NULL);
}

static char	**ft_create_str(char **result, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	end = 0;
	start = 0;
	i = 0;
	while (s[start] != '\0')
	{
		if (s[start] != c)
		{
			end = 0;
			while (s[end + start] != c && s[end + start] != '\0')
				end++;
			result[i] = ft_substr(s, start, end);
			if (result[i] == NULL)
				return (ft_free(result, i));
			i++;
			start += end;
		}
		else
			start++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
	{
		return (NULL);
	}
	result = (char **)malloc((how_many_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
	{
		return (NULL);
	}
	return (ft_create_str(result, s, c));
}

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

int	list_sorted(t_stack **stack)
{
	if (!stack)
		return (0);
	t_stack		*pnt;
	int			temp;

	pnt = *stack;
	temp = pnt->val;
	while (pnt->next)
	{
		if (temp > pnt->next->val)
			return (0);
		pnt = pnt->next;
		temp = pnt->val;
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
	new_node -> position = 0;
	new_node -> next = NULL;
	return (new_node);
}

void	add_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return;
	node -> next = *stack;
	*stack = node;
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*pnt;

	if (!stack || !node)
		return;
	if (!*stack)
	{
		add_front(stack, node);
		return;
	}
	pnt = *stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	pnt->next = node;
	node->next = NULL;
}

int	stack_size(t_stack *stack)
{
	unsigned int	size;
	t_stack			*pnt;

	size = 0;
	pnt = stack;
	while (pnt)
	{
		size++;
		pnt = pnt->next;
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

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a;
	t_stack *b;

	a = stack_a;
	b = stack_b;
	printf("stack_a		stack_b\n\n");
	while (a || b)
	{
		if (!a)
		{
			printf("<   -  >	<   %d  >\n", b -> val);
			b = b -> next;
		}
		else if (!b)
		{
			printf("<    %d  >	<   -  >\n", a -> val);
			a = a -> next;
		}
		else if(a && b)
		{
			printf("<   %d  >	<   %d  >\n", a -> val, b -> val);
			a = a -> next;
			b = b -> next;
		}
	}
	printf("----------------------------------\n\n");
}

int	last_node(t_stack **stack)
{
	t_stack *pnt;

	pnt = *stack;
	while (pnt->next)
	{
		pnt = pnt->next;
	}
	return (pnt->val);
}

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	long			min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node); 
}

void	put_indexs(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->position = 1;
		else
			stack->position = 0;
		stack = stack->next;
		++i;
	}
}

void	find_target(t_stack *b, t_stack *a)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int			best_match_index;

	while (b)
	{
		best_match_index = INT_MIN;
		current_a = a;
		while (current_a)
		{
			if (current_a->val < b->val && current_a->val > best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MIN)
			b->target_node = find_max(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int			best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val 
				&& current_a->val < best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	nodes_cost(t_stack *stack_b, t_stack *stack_a) 
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	
	while (stack_b)
	{
		stack_b->cost = stack_b->index;
		if (!(stack_b->position))
			stack_b->cost = len_b - (stack_b->index);
		if (stack_b->target_node->position)
			stack_b->cost += stack_b->target_node->index;
		else 
			stack_b->cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack			*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	sort_three(t_stack **stack_a)
{
	int 	biggest;
	t_stack	*s;

	s = *stack_a;
	biggest = s->val;
	while (s)
	{
		if (biggest < s->val)
			biggest = s->val;
		s = s->next;
	}
	if (biggest == (*stack_a)->val)
		ra_rb(stack_a, 'a');
	else if ((*stack_a)->next->val == biggest)
		rra_rrb(stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa_sb(stack_a, 'a');
}

void	min_on_top(t_stack **stack) 
{
	while (last_node(stack) != find_max(*stack)->val)
	{
		if (find_min(*stack)->position)
			ra_rb(stack, 'a');
		else
			rra_rrb(stack, 'a');
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *node, char ch)
{
	if (ch == 'b')
	{
		while (*stack != node)
		{
			if (node->position)
				ra_rb(stack, ch);
			else
				rra_rrb(stack, ch);
		}
	}
	else
	{
		while (last_node(stack) != node->val)
		{
			if (node->position)
				ra_rb(stack, ch);
			else
				rra_rrb(stack, ch);
		}
	}
}
	
void	find_rr(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	put_indexs(*a);
	put_indexs(*b);
}

void	find_rrr(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b); 
	put_indexs(*a);
	put_indexs(*b);
}

void	to_stack_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa_pb(a, b, 'a');
}

void	to_stack_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*cheapest_node;
	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->position && cheapest_node->target_node->position)
		find_rr(stack_b, stack_a, cheapest_node);
	else if (!(cheapest_node->position) && !(cheapest_node->target_node->position))
		find_rrr(stack_b, stack_a, cheapest_node);

	prep_for_push(stack_b, cheapest_node, 'b');
	prep_for_push(stack_a, cheapest_node->target_node, 'a');
	pa_pb(stack_a, stack_b, 'a');
}

int	to_mite(t_stack **stack, int les)
{
	int			num;
	int			tru;
	int			temp;
	t_stack		*pnt;
	
	pnt = (*stack);
	num = les;
	tru = 1;
	while (pnt)
	{
		if (pnt -> val > les && tru)
		{
			num = pnt -> val;
			tru = 0;
		}
		else  if (pnt -> val > les)
		{
			temp = pnt -> val;
			if (temp < num)
				num = temp;
		}
		pnt = pnt -> next;
	}
	return (num);
}

int smallest_num(t_stack **stack)
{
	int	big;
	int temp;
	t_stack		*pnt;

	pnt = (*stack);
	big = pnt -> val;
	while (pnt -> next)
	{
		temp = pnt -> next -> val;
		if (temp < big)
		{
			big = temp;
		}
		pnt = pnt -> next;
	}
	return (big);
}

int	find_mite(t_stack **stack, int n )
{
	 int mit;
	 int j;

	 mit = smallest_num(stack);
	 j = 1;
	while (n > j)
	{
		mit = to_mite(stack, mit);
		j++;
	}
	return (mit);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
    int mit;

    len = stack_size(*stack_a);
    mit = find_mite(stack_a, len / 2);
	pa_pb(stack_b, stack_a, 'b');
	while (len > 3 && !list_sorted(stack_a))
    {
        pa_pb(stack_b, stack_a, 'b');
		len--;
		if ((*stack_b)->val < mit)
			ra_rb(stack_b, 'b');
    }
	len = stack_size(*stack_b);
	while (len-- > 0)
	{
		put_indexs(*stack_a);
		put_indexs(*stack_b);
		find_target(*stack_b, *stack_a);
		nodes_cost(*stack_b, *stack_a);
		set_cheapest(*stack_b);
		to_stack_b(stack_b, stack_a);
	}
	put_indexs(*stack_a);
	min_on_top(stack_a);
}

char	**check_digit(char **str, int tru)
{
	int	i;
	int j;

	i = 0;
	if (!tru)
		i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				j++;
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

char	**ft_check_args(char **s, int n, char **str)
{
	if (n == 2 && s[1][0])
	{
		str = ft_split(s[1], ' ');
		str = check_digit(str, 1);
	}
	else
	{
		str = check_digit(s, 0);
		if (str)
			str++;
	}
	return (str);
}

void	to_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!list_sorted(&stack_a))
	{
		if (stack_size(stack_a) == 2)
		{
			if (stack_a->val > stack_a->next->val)
				sa_sb(&stack_a, 'a');
		}
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int n, char **s)
{
	// (void)nn;
	// (void)ss;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**str;
	int			num;
	int			i;
	//int			n;

	stack_a = NULL;
	stack_b = NULL;
	str = NULL;
	num = 0;
	i = 0;
	//n = 0;
	// char *s[7] = {"name", "5", "4", "0", "22", "77", NULL};
	
	// n = 7;
	str = ft_check_args(s, n, str);
	if (str && str[0])
	{
		while (str[i])
		{
			num = ft_atoi(str[i]);
			if (num == 0 && str[i][1] != '\0')
				return (printf("error\n"), 0);
			if (ft_int_valid(stack_a, num))
				return (free(stack_a), free(stack_b), printf("Error\n"), 0);
			add_back (&stack_a, create_new_node(num));
			i++;
		}
		to_sort(stack_a, stack_b);
		if (n == 2)
			free_str(str);
	}
	else
		printf("Error\n");
	return (0);
}
