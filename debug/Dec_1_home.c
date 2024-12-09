#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <limits.h> 


typedef struct s_stack
{
	int				val;
	int				index;
	int				pl;
	int				cost;
	int 			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack		*create_new_node(int num);
int			list_sorted(t_stack **stack);
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
int	        ft_atoi(const char *str);
int	        ft_isdigit(int ch);
void	print_stack(t_stack *stack, t_stack *stack_b);
void	sort_three(t_stack **stack_a);


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
	new_node -> pl = 0;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

void	add_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return;
	node -> next = *stack;
	if (*stack)
		(*stack)->prev = node;
	node->prev = NULL;
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
	node->prev = pnt;
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

int	last_node(t_stack *stack)
{
	t_stack *pnt;

	pnt = stack;
	while (pnt -> next)
	{
		pnt = pnt -> next;
	}
	return (pnt -> pl);
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
			stack->pl = 1;
		else
			stack->pl = 0;
		stack = stack->next;
		++i;
	}
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	int			best_match_index;

	while (a)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val >= best_match_index)
			{
				best_match_index = current_b->val;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
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

void	nodes_cost(t_stack *stack_a, t_stack *stack_b) 
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->pl))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target_node->pl)
			stack_a->cost += stack_a->target_node->index;
		else 
			stack_a->cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
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
	while ((*stack)->val != find_min(*stack)->val)
	{
		if (find_min(*stack)->pl)
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

void	prep_for_push(t_stack **stack, t_stack *top_node, char ch)
{
	while (*stack != top_node)
	{
		if (ch == 'a')
		{
			if (top_node->pl)
				ra_rb(stack, ch);
			else
				rra_rrb(stack, ch);
		}
		else if (ch == 'b')
		{
			if (top_node->pl)
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

void	to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->pl && cheapest_node->target_node->pl)
		find_rr(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->pl) && !(cheapest_node->target_node->pl))
		find_rrr(stack_a, stack_b, cheapest_node);

	prep_for_push(stack_a, cheapest_node, 'a'); 
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pa_pb(stack_b, stack_a, 'b');
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	while (stack_size(*stack_b) != 2 && !list_sorted(stack_a))
		pa_pb(stack_b, stack_a, 'b');
	len_a = stack_size(*stack_a);
	while (len_a-- > 3 && !list_sorted(stack_a))
	{
		put_indexs(*stack_a);
		put_indexs(*stack_b);
		find_target(*stack_a, *stack_b);
		nodes_cost(*stack_a, *stack_b);
		set_cheapest(*stack_a);
		to_stack_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		put_indexs(*stack_a);
		put_indexs(*stack_b);
		set_target_b(*stack_a, *stack_b);
		to_stack_a(stack_a, stack_b);
	}
	put_indexs(*stack_a);
	min_on_top(stack_a);
}

char	**ft_check_args(char **s, int *len, int n)
{
	int	i;
	int j;
	char **str;

	i = 1;
	str = s;
	if (n == 2)
	{
		str = ft_split(s[1], ' ');
		*len = 0;
		i = 0;
	}
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				j++;
			if (!ft_isdigit(str[i][j]))
				return (NULL);
			j++;
		}
		i++;
	}
	return (str);
}

int	main(int nn, char **ss)
{
	(void)nn;
	(void)ss;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**str;
	int			num;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	i = 1;

	int n = 2;
	// 50
	char *s[2] = {"name", "46 1 5 95 96 68 26 49 98 36 52 99 80 43 89 30 65 44 83 51 8 90 64 40 18 66 61 56 41 78 100 15 72 35 71 12 13 42 77 9 11 75 39 55 4 53 2 81 27 76"};
	// char *s[2] = {"name", "29 4 28 8 11 22 46 32 2 43 19 1 24 49 30 9 33 14 15 7 35 6 16 50 41 21 5 13 47 17 34 3 27 31 36 45 38 23 42 18 12 40 26 10 44 39 37 25 20 48 "};
	//char *s[2] = {"name", "10 1 34 21 28 6 41 12 24 47 2 50 22 40 35 3 37 26 7 20 15 48 46 19 14 29 42 5 30 25 13 18 8 17 38 23 32 39 44 43 11 45 33 36 31 49 9 27 16 4 "};
	// char *s[2] = {"name", "1 7 37 33 38 48 28 9 10 3 26 50 15 41 2 34 47 5 49 16 4 36 45 42 18 6 44 43 13 24 17 40 23 25 22 21 27 35 20 31 8 32 29 12 19 46 30 11 39 14 "};
	// char *s[2] = {"name", "23 28 2 14 38 26 3 24 27 36 33 40 19 42 18 30 13 41 35 16 47 11 15 43 29 50 44 34 39 21 10 32 46 48 1 25 12 45 17 7 9 20 8 22 6 31 4 49 37 5 "};
	//char *s[2] = {"name", "25 36 2 15 26 19 43 28 40 33 10 29 21 16 47 49 44 4 48 11 31 45 41 23 38 8 37 9 35 22 32 20 13 46 30 27 5 42 1 34 7 14 12 18 24 50 17 3 39 6"};
	
	// -----------------------------------------------

	// 100
	//char *s[2] = {"name", ""};
		// char *s[2] = {"name", " 29 77 52 1 70 25 72 79 92 40 19 93 43 39 26 24 4 7 5 28 67 98 100 30 91 44 96 13 22 6 65 74 85 14 66 34 23 35 71 11 41 59 78 45 62 37 84 9 73 99 83 69 48 17 58 31 21 20 18 2 46 86 87 88 33 10 80 51 15 82 3 38 89 95 32 50 53 8 68 12 94 97 54 36 57 27 47 60 81 49 63 64 90 75 16 76 42 61 56 55"};
		// char *s[2] = {"name", "4 80 81 12 35 90 57 38 3 50 33 56 55 98 5 7 34 97 14 51 48 15 95 67 22 92 71 21 70 41 19 85 53 17 31 99 26 20 87 23 82 79 61 29 32 11 54 43 69 89 84 28 58 62 60 72 86 25 2 59 49 9 1 76 39 91 16 47 18 36 66 42 96 100 94 10 64 13 83 73 6 45 77 24 93 27 40 68 88 44 30 63 65 8 74 46 37 75 52 78 "};
		// char *s[2] = {"name", "54 17 52 92 50 69 2 4 76 72 73 7 57 59 95 68 47 25 62 78 26 44 32 100 9 97 81 67 1 75 64 19 5 8 90 3 56 13 24 35 91 6 36 15 40 61 84 77 43 65 63 28 41 87 49 94 74 39 89 23 71 18 80 46 12 79 38 29 33 30 83 48 11 88 53 45 51 96 58 70 93 31 86 98 34 99 10 60 85 21 14 82 20 27 42 66 55 16 22 37 "};
		//char *s[2] = {"name", "15 94 84 29 48 60 16 78 32 66 59 51 81 27 100 35 12 95 13 38 21 80 62 57 91 40 25 1 34 65 56 68 55 31 58 89 42 54 53 23 74 19 28 47 52 61 82 67 96 37 72 9 22 50 20 93 83 6 36 2 92 26 75 45 30 85 87 70 73 14 10 33 71 98 77 17 5 24 86 8 49 79 39 4 99 46 41 7 11 88 43 76 18 64 3 97 63 44 90 69 "};
		// char *s[2] = {"name", "68 17 83 20 15 66 70 12 18 4 74 14 48 45 42 43 99 49 73 21 50 57 94 85 30 2 36 8 97 88 24 56 93 55 64 69 5 92 19 11 31 9 23 71 46 53 98 100 39 54 33 62 96 6 52 76 75 63 84 78 3 47 95 60 90 27 13 28 72 67 86 91 41 38 10 77 35 34 26 87 89 25 22 58 32 1 79 65 80 29 16 59 44 7 81 37 82 40 51 61 "};
	//--------------------------------------------------------------

	// 500
	//char *s[2] = {"name", "382 178 489 79 349 41 33 470 471 118 181 285 276 434 236 484 480 13 32 415 344 458 20 224 196 413 348 134 42 358 76 55 68 81 440 453 23 432 108 263 199 169 326 306 102 132 125 322 126 314 373 213 425 48 299 136 142 242 333 463 474 238 277 384 447 416 87 353 154 377 401 446 388 288 80 190 318 47 24 264 407 195 44 88 309 472 15 97 445 115 304 250 350 301 84 443 490 175 69 107 449 185 266 494 493 170 469 300 56 177 437 25 436 255 219 234 93 330 428 336 131 201 198 444 441 2 429 77 214 9 371 18 141 3 325 423 403 249 272 481 297 287 402 477 372 351 289 11 117 109 427 40 16 321 424 267 12 483 95 457 243 426 21 383 406 230 456 362 378 62 129 149 100 38 7 61 111 139 209 150 420 180 45 282 78 323 338 110 295 435 174 228 419 10 140 182 291 28 210 205 8 431 290 394 260 227 409 468 418 99 320 167 422 439 101 254 59 256 310 184 307 400 485 192 83 408 168 324 6 152 187 346 397 67 497 354 499 396 270 151 405 158 75 312 51 379 438 357 305 204 50 460 235 387 163 160 487 49 251 37 232 138 208 89 450 39 390 17 31 398 162 119 292 328 317 121 120 393 218 366 27 268 147 341 237 335 479 482 252 220 197 345 342 386 128 399 191 360 475 35 66 179 233 127 452 91 98 311 53 148 106 464 327 308 173 370 404 376 124 430 156 332 216 103 4 364 417 130 5 488 273 60 114 63 253 165 186 189 355 359 155 294 43 275 284 381 19 392 221 281 70 171 498 316 283 245 391 412 112 257 365 367 105 280 473 363 274 451 29 226 278 172 14 369 34 36 414 231 26 240 259 85 421 211 72 202 215 176 279 476 239 455 343 161 334 54 104 248 269 52 144 389 71 74 495 265 164 315 200 442 465 183 244 113 385 94 133 433 82 246 135 73 86 222 368 448 166 411 296 261 298 356 461 153 380 193 188 329 145 352 194 454 203 478 207 462 96 217 22 340 212 331 262 57 225 247 206 486 143 303 395 241 467 500 459 159 496 122 271 374 223 157 229 361 64 286 410 302 116 90 313 319 347 30 92 1 491 293 146 492 65 339 466 58 337 46 258 375 123 137"};
	// char *s[2] = {"name", "161 63 164 476 101 441 375 448 137 435 458 14 276 308 463 51 57 449 386 265 165 411 127 498 134 140 87 220 350 79 395 342 483 423 457 427 298 340 318 160 116 409 488 132 370 438 351 114 55 112 93 75 35 117 274 302 482 361 38 325 201 383 288 187 200 195 233 46 42 128 481 60 459 124 231 380 50 271 402 295 470 284 349 224 177 148 310 47 473 442 71 331 277 406 305 450 91 336 434 95 175 467 159 309 287 4 80 20 443 416 495 289 270 123 158 447 258 218 369 256 436 281 323 257 155 126 105 261 304 104 357 307 394 290 169 364 190 194 390 58 203 332 207 53 424 118 374 455 227 245 122 96 316 168 62 16 496 212 68 102 241 225 37 210 52 73 234 28 500 249 150 78 315 400 198 41 410 130 327 404 77 139 23 250 226 460 358 115 491 444 56 328 30 45 414 376 421 49 311 399 100 142 360 412 437 240 31 214 1 461 474 385 492 65 138 232 294 260 204 283 121 366 280 191 273 324 183 237 156 216 330 230 89 192 39 429 251 108 84 293 381 382 286 29 268 196 157 236 314 362 94 221 341 378 487 279 13 145 335 263 285 143 419 153 107 486 184 125 44 97 326 396 136 422 69 182 428 346 299 420 368 33 15 391 85 111 27 246 86 272 229 109 465 489 319 253 303 66 452 464 22 334 25 379 445 19 398 179 415 479 348 222 43 151 462 469 297 339 239 365 185 388 373 147 144 219 322 202 345 180 417 352 301 61 485 337 67 405 6 244 18 167 266 32 7 17 21 347 189 243 98 106 425 401 264 321 343 440 99 480 242 26 403 154 146 367 131 149 211 468 238 377 269 439 70 475 247 209 12 320 426 5 72 83 135 208 354 152 275 291 413 355 371 278 48 392 433 262 329 119 10 418 176 40 90 432 163 199 451 344 356 113 8 2 193 363 282 408 466 454 267 493 133 407 206 110 103 446 174 359 188 259 499 254 92 389 82 317 255 497 213 172 129 472 120 353 59 477 471 313 456 228 384 296 292 197 223 338 24 484 141 453 430 235 478 494 178 397 74 3 81 217 54 11 88 162 170 76 34 431 215 166 181 173 36 205 64 248 372 387 312 186 252 393 171 333 490 300 306 9"};
	// char *s[2] = {"name", "149 161 84 465 393 211 324 194 390 491 487 452 477 195 298 439 335 145 235 220 254 326 216 369 184 384 191 94 20 136 494 273 148 48 269 6 460 133 171 282 352 18 284 304 181 296 187 98 9 410 185 437 330 34 373 265 421 473 165 361 416 103 43 223 412 17 117 256 222 246 323 35 234 334 305 99 163 146 287 4 307 26 267 65 60 244 207 316 127 206 385 257 173 170 12 5 321 492 140 404 131 368 63 102 203 197 353 135 312 108 143 8 283 436 493 210 471 370 81 54 132 36 475 382 154 52 251 75 427 214 333 435 88 38 152 294 461 100 217 242 450 355 338 76 297 150 417 395 74 62 463 137 3 96 315 193 53 467 375 204 441 367 236 472 44 391 400 86 241 16 350 336 129 447 279 228 182 396 199 428 113 481 411 259 14 455 147 291 67 226 302 486 398 186 89 232 356 123 116 387 252 488 354 318 142 426 255 320 482 23 280 231 121 158 372 378 49 403 25 209 434 83 313 262 71 480 414 308 58 442 331 79 253 190 278 325 453 397 21 424 363 219 408 364 80 402 311 200 93 337 260 431 107 70 405 213 317 478 451 285 497 245 341 42 106 11 406 7 409 61 445 272 495 413 120 126 365 490 485 250 295 85 130 344 183 328 430 134 332 118 19 188 289 46 177 293 128 114 483 109 422 429 87 322 175 33 327 29 314 162 476 239 208 376 57 268 198 110 443 423 418 105 309 168 178 261 371 73 141 360 166 464 66 22 474 201 303 432 153 167 115 458 77 457 72 31 10 462 27 224 263 59 189 124 448 392 92 366 274 420 247 230 498 433 125 264 30 39 349 290 438 425 380 374 351 401 180 249 174 281 179 466 2 32 82 386 258 286 379 276 345 310 95 288 90 101 91 419 1 489 24 229 484 233 78 347 456 37 479 383 227 469 394 176 399 144 212 205 97 270 172 243 221 169 157 468 192 41 56 339 40 15 300 248 238 225 362 446 119 122 271 415 196 156 55 454 306 301 164 69 449 68 342 381 159 343 275 155 51 499 45 104 496 329 407 292 470 500 266 389 139 358 47 346 13 138 388 50 377 202 240 444 218 112 151 64 28 357 111 215 340 299 277 440 237 319 348 359 459 160"};
	// char *s[2] = {"name", "335 463 156 135 127 293 420 57 315 3 174 38 69 55 380 200 91 486 111 449 71 88 12 334 417 89 427 410 5 139 478 446 166 373 436 128 357 263 176 45 165 418 259 494 188 120 195 496 11 401 329 75 441 70 453 247 432 28 76 328 298 364 238 450 429 103 350 366 361 460 485 489 68 292 303 275 81 124 283 162 84 252 306 240 132 32 480 469 323 472 434 360 286 267 476 138 483 422 379 437 222 279 36 296 319 451 354 355 232 300 227 169 337 13 498 78 185 241 234 54 134 310 1 191 142 419 149 382 342 475 67 207 466 93 374 204 388 495 163 49 349 499 64 493 443 77 301 210 260 157 151 407 104 123 290 92 405 125 399 27 150 400 396 114 362 203 2 254 82 398 146 358 160 327 282 255 228 253 423 258 487 457 304 386 339 170 492 214 346 242 317 193 266 131 352 51 383 289 274 257 194 22 311 376 85 440 444 431 470 117 179 500 308 468 482 445 458 435 497 172 220 490 80 44 215 43 83 421 338 205 168 324 230 381 424 233 439 276 307 26 297 391 140 426 406 196 363 141 488 52 322 159 428 115 158 129 98 287 473 345 31 16 462 229 190 438 9 59 272 413 231 280 336 14 56 331 368 24 107 481 180 433 491 402 171 243 130 278 474 377 20 288 235 62 403 221 372 347 94 21 299 284 50 326 119 73 106 415 46 356 344 244 19 265 291 105 86 425 177 389 74 384 173 321 189 237 269 112 273 250 148 199 212 371 264 18 29 99 375 116 133 23 66 448 65 314 239 340 8 271 216 10 152 369 365 211 408 30 206 147 4 126 219 109 416 208 15 72 113 464 182 101 465 353 217 430 186 153 164 42 225 261 184 316 202 414 294 461 378 270 175 285 452 143 100 370 477 333 394 455 110 302 155 397 295 404 256 367 359 268 209 122 213 467 47 459 121 6 198 197 39 390 60 40 471 343 409 25 332 392 245 97 411 236 108 35 325 136 95 277 341 348 320 183 53 154 484 330 393 281 17 223 96 318 187 456 167 102 246 87 249 479 137 312 178 37 305 41 447 161 48 90 192 145 395 181 58 33 313 144 34 262 63 224 251 118 61 218 7 226 442 248 79 201 309 412 385 454 387 351"};
	//char *s[2] = {"name", " 244 95 197 422 310 292 128 336 325 396 155 259 172 302 134 275 116 65 453 316 426 91 40 443 424 425 169 288 475 109 436 85 260 315 334 280 455 1 423 408 257 137 145 9 208 279 466 140 69 388 60 36 447 365 158 52 38 469 154 337 238 384 99 98 188 445 263 34 213 328 23 387 146 322 352 375 136 283 308 39 124 152 484 127 133 161 407 392 185 67 121 182 6 285 391 103 233 177 18 210 307 246 278 397 269 239 309 294 27 186 14 363 45 266 416 444 450 26 62 311 460 32 10 473 431 286 299 57 147 362 472 461 389 297 223 427 335 326 153 11 78 413 64 395 113 245 117 207 148 258 126 467 373 487 199 366 175 2 374 179 240 354 470 256 267 497 101 97 46 491 76 319 157 417 496 33 217 105 102 58 290 138 183 243 355 50 74 187 262 180 194 485 86 41 230 119 206 237 318 107 320 327 205 402 252 55 376 54 90 93 234 82 393 277 364 449 499 7 135 159 251 372 414 346 236 227 435 405 224 452 268 324 306 49 77 211 61 284 92 488 35 477 156 43 404 226 486 270 379 480 59 314 13 204 125 28 439 195 494 143 75 264 398 300 289 265 209 111 20 42 44 403 19 410 142 201 498 344 368 84 15 434 465 489 377 51 448 212 428 16 31 381 96 383 12 463 421 474 273 222 339 56 254 163 118 357 440 415 165 329 110 166 349 458 181 409 106 37 271 430 214 24 343 247 495 382 231 419 371 331 348 304 232 29 433 360 456 457 225 151 122 192 202 191 394 215 321 160 471 219 481 345 380 100 63 296 184 442 25 351 48 66 8 164 438 170 429 298 281 47 131 274 5 168 418 139 248 79 303 249 242 250 129 167 454 261 493 72 108 123 68 162 114 462 73 390 468 483 350 104 83 218 174 412 441 235 353 221 399 332 190 411 347 400 479 340 282 330 323 492 356 115 132 385 144 3 253 216 189 193 370 341 130 149 203 476 291 171 367 272 312 196 71 241 80 451 420 406 220 333 200 4 317 255 176 369 313 89 293 70 228 358 53 120 478 141 173 437 342 500 229 446 178 490 150 432 301 17 94 198 459 30 305 338 378 87 22 276 88 482 21 112 359 295 81 401 361 464 386 287"};
	////////char *s[2] = {"name", "146 317 380 494 175 127 107 360 354 470 148 30 172 343 131 46 106 450 233 94 29 293 444 297 105 236 496 248 366 151 110 232 128 308 489 51 344 219 425 52 91 50 123 72 352 264 89 428 206 133 11 75 221 34 194 86 112 16 432 253 336 177 495 161 68 140 345 120 266 423 481 282 4 349 156 390 365 418 292 404 104 109 394 7 178 389 40 413 279 93 323 26 276 399 427 256 245 398 113 188 200 429 19 20 218 39 270 377 306 314 359 440 328 66 456 401 476 446 142 217 466 143 434 125 290 364 403 340 289 286 185 324 38 227 426 101 99 158 420 163 460 309 357 204 115 202 315 304 412 28 191 155 97 118 333 12 319 356 79 210 448 285 491 195 492 181 246 347 228 71 361 103 329 1 468 36 211 251 53 235 433 322 135 318 411 42 169 307 370 383 18 10 416 77 33 2 81 295 430 252 82 164 187 119 137 299 244 6 23 3 371 387 203 25 136 313 465 5 467 216 134 388 431 168 499 14 422 157 242 224 482 280 335 17 255 183 353 205 144 298 152 391 173 261 300 414 417 348 393 63 498 138 392 355 231 438 287 478 435 326 339 199 48 419 57 479 337 159 108 64 259 69 193 35 458 487 369 386 283 397 129 342 269 376 100 130 454 485 114 268 87 274 363 171 47 197 331 223 250 302 452 32 73 116 439 84 230 497 149 278 442 263 459 408 475 272 395 150 111 74 310 247 27 59 220 121 166 281 312 415 305 154 436 201 332 215 162 373 381 469 338 153 243 189 139 358 212 484 249 13 362 480 213 463 284 330 31 61 8 325 240 400 410 15 145 262 437 483 451 124 192 55 174 453 83 76 102 407 141 490 273 98 351 234 327 96 320 488 406 65 461 179 260 147 296 85 382 375 301 60 37 45 180 254 471 493 294 80 24 486 225 186 70 477 474 271 241 405 447 167 346 90 226 165 117 222 385 182 56 472 196 198 126 207 54 67 288 49 372 58 500 62 396 473 303 132 237 43 267 457 441 208 367 464 78 291 341 41 265 21 22 184 374 214 277 176 350 321 88 384 424 378 209 334 462 95 160 44 455 379 409 92 368 421 275 443 402 229 239 257 122 238 190 449 445 9 170 316 311 258 "};
	//char *s[2] = {"name", "250 249 336 467 26 392 246 93 238 381 42 163 473 137 64 71 378 72 479 396 391 123 405 173 256 266 203 204 80 439 133 97 108 449 185 442 367 197 254 195 277 3 39 104 181 415 21 244 331 49 435 245 7 419 177 61 176 423 6 431 158 131 366 310 289 143 207 444 242 465 459 469 1 462 17 450 4 146 107 43 417 231 128 364 234 340 389 437 144 326 92 186 472 312 500 115 339 425 151 147 281 430 319 85 118 377 113 183 228 276 51 491 361 292 452 482 40 275 219 371 136 464 223 356 12 132 355 314 196 456 346 194 375 168 304 192 50 410 33 274 408 75 98 349 458 116 321 90 149 403 374 457 451 468 477 255 84 455 390 260 285 27 358 120 257 142 382 329 101 76 91 237 145 55 344 352 68 305 497 233 229 178 311 335 293 52 9 217 119 199 384 440 114 376 160 318 484 387 436 372 287 476 486 341 94 140 288 298 333 485 278 152 434 44 414 135 190 264 404 155 488 453 215 187 493 280 400 96 308 32 328 332 263 443 172 259 303 216 398 438 222 174 294 302 369 428 53 102 393 153 225 463 495 209 8 282 268 74 36 141 45 54 402 212 324 220 265 11 157 227 15 397 110 241 201 248 63 65 322 180 56 487 334 330 14 117 365 297 79 218 188 315 306 239 184 129 22 67 320 385 100 99 206 69 232 291 13 48 62 247 411 480 441 357 213 412 496 106 471 492 226 28 38 148 5 421 483 490 154 416 221 388 125 345 240 270 299 191 273 426 300 24 461 407 202 343 394 279 31 447 150 286 105 475 161 418 317 337 253 77 295 200 429 323 348 327 134 283 19 427 499 70 35 60 138 10 478 395 494 271 193 88 208 370 261 446 262 210 171 354 362 380 83 301 498 224 130 18 313 162 316 252 433 66 379 413 20 383 342 89 214 111 126 445 57 166 347 139 112 290 409 46 81 251 29 284 169 474 360 205 30 386 325 86 466 489 16 432 422 338 156 189 307 272 175 34 359 47 230 399 165 170 37 73 167 258 373 420 401 164 267 363 41 23 351 25 95 424 243 368 350 198 122 235 211 82 296 59 406 460 87 269 121 182 481 448 159 179 58 127 78 454 236 309 470 109 103 353 2 124 "};

	// -------------------------------------------------------------------------------------------------
	str = ft_check_args(s, &i, n);
	if (n > 1 && str)
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
	}
	return (0);
}