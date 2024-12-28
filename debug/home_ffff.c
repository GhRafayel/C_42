#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
typedef struct s_stack
{
	int				val;
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
int	        ft_atoi(const char *str);
int	        ft_isdigit(int ch);
void	print_stack(t_stack *stack, t_stack *stack_b);


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
		}
		else if (!b)
		{
			printf("<    %d  >	<   %c  >\n", p -> val, a);
		}
		else
		{
			printf("<   %d  >	<   %d  >\n", p -> val, b -> val);
		}
		if (!p)
		{
			b = b -> next;
		}
		else if (!b)
		{
			p = p -> next;
		}
		else
		{
			p = p -> next;
			b = b -> next;
		}
		
	}
	printf("----------------------------------\n\n");
}

int rang(int a, int b)
{
	int res = a - b;

	if (res < 0)
		res *= -1;
	if (a > b)
		res -= 1;
	return (res);
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



int	find_biggist(t_stack **stack)
{
	int			num;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt -> val;
	while (pnt)
	{
		if(pnt -> val > num)
		{
			num = pnt -> val;
		}
		pnt = pnt -> next;
	}
	
	return (num);
}

int	is_biggist(t_stack **stack)
{
	int			num;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt -> val;
	while (pnt)
	{
		if(pnt -> val > num)
		{
			return (0);
		}
		pnt = pnt -> next;
	}
	return (1);
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
	while (pnt -> next)
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
	 j = 0;
	while (n > j)
	{
		mit = to_mite(stack, mit);
		j++;
	}
	return (mit);
}

int find_min_rang(t_stack **stack_a, int b_val, int *num)
{
	int			num2;
	int			num3;
	t_stack		*a;

	a = *stack_a;
	num2 = rang(a -> val, b_val);
	*num = a -> val;
	while (a)
	{
		num3 = rang(a -> val, b_val);
		if (num2 > num3)
		{
			num2 = num3;
			*num = a->val;
		}
		if (num2 == num3)
		{
			if (*num > a->val)
				*num = a->val;
		}
		a = a -> next;
	}
	return (num2);
}

int	find_pl(t_stack **stack, int num)
{
	int			i;
	t_stack		*pnt;

	pnt = (*stack);
	i = 0;
	while (pnt)
	{
		if(pnt -> val == num)
			break;
		pnt = pnt -> next;
		i++;
	}
	return (i);
}

void	found_doub_op_1(t_stack **stack_a, t_stack **stack_b, int *i)
{
	if(stack_size(*stack_b) > 1 && stack_size(*stack_a) > 1)
	{
		if ((*stack_b) -> val < (*stack_b) -> next -> val)
		{
			if ((*stack_a) -> val > (*stack_a) -> next -> val)
			{
				ss(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				sa_sb(stack_b, 'b');
				i+=1;
			}
		}
		// else if ((*stack_a) -> val > (*stack_a) -> next -> val)
		// {
		// 	sa_sb(stack_a, 'a');
		// 		i+=1;
		// }
	}
}

void	found_doub_op_2(t_stack **stack_a, t_stack **stack_b, int *i, int center)
{
	if (stack_size(*stack_a) > 2 && stack_size(*stack_b) > 2)
	{
		if (rang((*stack_b) -> val, (*stack_b) -> next -> val) > rang((*stack_b) -> val, last_node(*stack_b)))
		{
			if (rang((*stack_a) -> val, (*stack_a) -> next -> val) > rang((*stack_a) -> val, last_node(*stack_a)) && (*stack_a) -> val > center)
			{
				rr(stack_a, stack_b);
				*i += 1;
			}
			else
			{
				ra_rb(stack_b, 'b');
				*i += 1;
			}
		}
		else if (rang((*stack_a) -> val, (*stack_a) -> next -> val) > rang((*stack_a) -> val, last_node(*stack_a)) && (*stack_a) -> val > center)
		{
			ra_rb(stack_a, 'a');
				*i += 1;
		}
	}
}

void	found_doub_op_3(t_stack **stack_a, t_stack **stack_b, int *i, int center)
{
	if (stack_size(*stack_a) > 2 && stack_size(*stack_b) > 2)
	{
		if (rang((*stack_a) -> val, (*stack_a) -> next -> val) > rang((*stack_a) -> val, last_node(*stack_a)))
		{
			if (rang((*stack_b) -> val, (*stack_b) -> next -> val) > rang((*stack_b) -> val, last_node(*stack_b)) && (*stack_b) -> val < center)
			{
				rr(stack_a, stack_b);
				*i+=1;
			}
			else
			{
				ra_rb(stack_a, 'a');
				*i+=1;
			}
		}
		else if (rang((*stack_b) -> val, (*stack_b) -> next -> val) > rang((*stack_b) -> val, last_node(*stack_b)) && (*stack_b) -> val > center)
		{
			ra_rb(stack_b, 'b');
				*i+=1;
		}
		else if ( last_node(*stack_b) > center && last_node(*stack_b) > (*stack_b) -> val)
		{
			rra_rrb(stack_b, 'b');
		}
	}
}

int to_stack_b(t_stack **stack_a, t_stack **stack_b, int center, int n)
{
	int i;

	i = 0;
	while (n && stack_size(*stack_a) > 2)
	{
		found_doub_op_2(stack_a, stack_b, &i, center);
		found_doub_op_1(stack_a, stack_b, &i);
		if ((*stack_a) -> val <= center)
		{
			pa_pb(stack_b, stack_a, 'b');
			
			i++;
			n--;
		}
		else
		{
			ra_rb(stack_a, 'a');
				i++;
		}
	}
	return (i);
}
/*
int to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	int s_len = stack_size(*stack_b);
	
	while (s_len > 1)
	{
		if ((*stack_b) -> val < (*stack_b) -> next -> val)
		{
			sa_sb(stack_b, 'b');
		}
		if(!is_biggist(stack_b))
		{
			if (find_biggist(stack_b) > stack_size(*stack_b) / 2)
			{
				rra_rrb(stack_b, 'b');
				i++;
				//
				
			}
			else
			{
				ra_rb(stack_b, 'b');
				i++;
				//
			}
		}
		else
		{
			pa_pb(stack_a, stack_b, 'a');
			//
			s_len--;
			i++;
		}
	}
	return (i);
}
*/
void	to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int num;
				

	while (stack_size(*stack_b) > 0)
	{
		int a = find_min_rang(stack_a, (*stack_b) -> val, &num);
		int b = find_min_rang(stack_a, last_node(*stack_b), &num);

		if ( a > b)
		{
			find_min_rang(stack_a, last_node(*stack_b), &num);

			if (find_pl(stack_a, num) >= stack_size(*stack_a) / 2)
			{
				rrr(stack_a, stack_b);
				

			}
			else
			{
				rra_rrb(stack_b, 'b');
				
			
			}
			//pa_pb(stack_a, stack_b, 'a');
		}
		else
		{
			find_min_rang(stack_a, (*stack_b) -> val, &num);
			if (num != (*stack_a) -> val && (*stack_b) -> val != num)
			{
				if (find_pl(stack_a, num) <= stack_size(*stack_a) / 2)
				{
					if ((*stack_b) -> val < num)
					{
						while (last_node(*stack_a) != num)
						{
							ra_rb(stack_a, 'a');
							
						}
					}
					else
					{
						while ((*stack_a) -> val != num)
						{
							ra_rb(stack_a, 'a');
							
						}
					}
					
				}
				else
				{
					if ((*stack_b)-> val < num )
					{
						while (last_node(*stack_a) != num )
						{
							rra_rrb(stack_a, 'a');
						}
						if (num == find_biggist(stack_a))
						{
							rra_rrb(stack_a, 'a');
						}
					}
					else
					{
						while ((*stack_a) -> val != num)
						{
							rra_rrb(stack_a, 'a');
							
						}
					}
				}

			}
			pa_pb(stack_a, stack_b, 'a');
		}
			
		

	}
	}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int len;
	int big;
	int n;

	n = 2;
	len = stack_size(*stack_a);
	n = len / 5;
	if (len >= 500)
		n = len / 7;
	while (stack_size(*stack_a) > 2)
	{
		to_stack_b(stack_a, stack_b, find_mite(stack_a, n), n);
	}

	to_stack_a(stack_a, stack_b);

	big =  find_biggist(stack_a);

	while (last_node(*stack_a) != big)
	{
		if (find_pl(stack_a, big) < len / 2)
		{
			ra_rb(stack_a, 'a');
		}
		else
		{
			rra_rrb(stack_a, 'a');
			
		}
	}	
}

void	to_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 3 && !list_sorted(*stack_a, 'a'))
	{
		while (!list_sorted(*stack_a, 'a'))
		{
			if ((*stack_a) -> val > last_node(*stack_a))
				ra_rb(stack_a, 'a');
			else if ((*stack_a) -> val > (*stack_a) -> next -> val)
				sa_sb(stack_a, 'a');
			else
				rra_rrb(stack_a, 'a');
		}
	}
	else if (!list_sorted(*stack_a, 'a'))
		sort(stack_a, stack_b);
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

int	main(int n, char **s)
{
	// (void)nn;
	// (void)ss;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**str;
	int			num;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	i = 1;

	//int n = 2;
	//char *s[2] = {"name", "75 91 82 "};
	// 50
	//char *s[2] = {"name", "36 8 5 47 19 6 41 7 29 13 46 22 12 14 49 43 11 4 23 40 1 45 3 37 27 21 39 42 34 16 17 28 50 38 2 44 48 25 24 32 10 35 33 18 15 9 20 31 26 30"};
	//char *s[2] = {"name", "24 1 7 3 49 18 42 31 20 19 34 38 48 23 15 2 21 25 13 4 43 50 37 14 47 29 46 40 26 9 28 27 36 33 11 45 5 39 10 35 32 6 41 8 44 22 17 30 12 16"};
	//char *s[2] = {"name", "27 11 10 15 12 24 5 13 6 4 18 22 30 37 45 47 28 8 32 20 46 31 48 26 41 21 25 23 1 39 17 44 34 3 49 33 35 38 2 29 14 36 7 50 42 16 19 43 40 9"};
	//char *s[2] = {"name", "21 6 26 4 42 19 44 24 11 37 15 30 27 8 25 35 41 10 13 31 32 28 16 48 12 7 33 43 39 1 22 9 46 17 34 2 14 3 40 5 36 18 38 20 29 23 49 47 50 45"};
	//char *s[2] = {"name", "46 33 44 50 30 10 34 18 26 49 28 7 19 15 3 38 36 4 12 22 8 20 41 45 43 29 48 17 14 5 21 32 2 40 37 39 1 25 16 9 24 27 31 23 6 13 11 42 35 47"};
	// ------------------------------------------------------------------------------------------------------------------------------------------
	
	// 100
	//char *s[2] = {"name", "56 31 51 79 76 39 66 46 20 80 52 44 36 87 9 2 99 47 63 69 61 45 98 65 54 82 71 22 67 23 48 37 94 72 92 34 29 18 11 28 21 13 75 27 10 96 83 50 6 12 84 97 16 88 95 17 33 85 60 25 7 19 42 78 26 1 30 77 43 64 100 70 73 3 68 74 14 86 93 40 15 91 53 49 32 62 57 4 5 24 81 59 55 41 35 90 8 89 38 58"};
	//char *s[2] = {"name", "75 91 82 8 43 76 31 5 44 81 74 64 32 20 7 100 33 25 68 45 48 62 73 95 93 13 59 6 22 94 69 10 37 71 57 35 49 50 89 83 30 21 88 78 27 90 28 16 84 52 61 41 46 72 40 54 2 11 56 63 80 24 47 86 17 23 14 9 3 67 18 79 99 1 87 98 70 96 60 38 4 42 34 97 39 85 51 77 53 26 19 66 29 65 92 15 36 55 58 12"};
	//char *s[2] = {"name", "80 65 10 89 58 84 11 42 7 75 100 14 62 45 20 43 5 31 24 81 23 56 98 36 27 67 69 35 93 4 6 90 59 19 38 34 15 52 16 78 83 21 68 76 63 64 2 70 51 41 72 13 9 18 95 55 30 91 54 86 37 28 53 1 85 71 40 12 96 73 26 8 17 50 47 32 92 97 33 39 3 25 87 61 60 49 44 94 79 74 22 57 88 29 46 82 99 77 48 66"};
	//char *s[2] = {"name", "28 29 34 37 13 23 11 88 8 46 3 45 24 30 89 96 36 15 56 41 76 85 59 39 52 53 72 40 47 38 5 21 44 48 90 19 61 12 57 43 81 70 1 27 94 63 31 82 97 51 68 69 17 33 100 78 9 4 14 60 87 95 25 65 55 99 83 2 98 20 93 86 71 67 18 50 75 62 77 73 74 66 42 6 58 22 64 84 49 79 16 10 54 7 92 32 91 26 35 80"};
	//char *s[2] = {"name", "83 63 68 92 17 50 20 53 58 81 24 26 32 18 65 96 13 19 46 85 64 88 72 7 94 37 57 55 82 21 2 71 29 79 27 80 36 31 90 97 1 25 38 89 93 22 11 8 54 9 56 86 4 98 34 6 14 99 59 78 87 47 69 12 76 84 66 35 73 39 43 42 48 3 62 61 41 23 49 16 77 67 5 51 91 15 75 70 28 44 60 30 33 40 95 45 52 10 100 74"};
	// ------------------------------------------------------------------------------------------------------------------------------------------

	// 500
	//char *s[2] = {"name", "374 496 47 417 471 393 105 458 492 126 89 385 407 79 234 402 457 187 340 45 191 474 320 228 249 265 150 61 130 300 323 472 178 343 486 317 447 336 475 270 481 450 72 339 223 307 170 219 233 175 408 401 459 101 436 55 377 283 476 70 383 370 31 119 87 242 305 448 143 280 462 389 239 494 221 263 259 427 418 146 60 69 98 395 216 180 156 466 287 182 173 367 29 132 315 288 330 409 255 196 381 446 332 258 351 262 22 294 292 91 129 461 154 310 366 85 8 201 232 124 473 190 246 261 54 185 452 157 420 38 133 396 13 500 391 338 306 321 121 80 331 222 432 464 304 93 11 56 24 148 241 493 122 260 412 373 135 229 441 75 225 345 406 149 165 10 299 415 176 161 439 256 247 140 437 17 15 308 266 444 289 369 327 364 498 251 273 477 429 3 342 379 59 204 76 227 248 212 213 19 110 96 445 139 314 7 480 268 282 203 495 285 160 52 164 469 269 163 207 491 443 172 337 435 65 5 40 309 66 394 302 244 169 73 147 26 74 49 387 277 111 83 318 312 195 356 319 184 107 325 291 334 272 479 355 440 490 254 236 103 46 478 252 453 423 313 456 99 460 18 64 384 361 112 127 257 152 220 224 240 422 62 390 398 326 354 301 499 94 303 341 177 484 278 271 411 42 189 145 433 202 465 32 403 421 41 284 141 237 179 117 35 77 322 33 116 226 167 4 1 276 193 290 88 215 30 108 372 425 483 159 297 39 245 405 400 426 114 142 181 27 214 414 316 419 416 487 238 67 344 488 347 78 81 90 131 137 100 413 16 274 158 217 113 428 451 235 467 118 192 455 51 449 329 197 168 23 97 155 134 50 359 296 9 120 430 218 57 264 470 281 36 468 171 68 211 104 84 333 250 349 353 174 438 208 482 231 275 63 162 350 346 363 295 82 434 352 115 365 125 138 360 136 71 392 200 166 230 194 358 6 48 399 243 431 28 267 380 335 206 198 199 20 485 34 375 21 95 324 378 357 205 37 210 92 382 106 410 328 144 151 153 58 44 12 183 454 397 102 293 43 86 376 186 424 279 386 128 362 497 188 286 2 253 348 463 371 109 489 123 442 298 311 14 53 404 388 25 368 209"};
	//char *s[2] = {"name", "399 170 328 91 479 53 386 191 293 88 222 355 301 280 402 327 332 473 441 118 242 138 221 63 149 489 468 330 340 186 72 297 42 303 77 164 329 335 177 257 398 175 54 273 309 462 393 127 314 117 231 87 256 76 299 153 400 7 352 391 156 271 377 105 368 28 199 166 322 390 461 215 342 401 438 36 384 168 8 218 214 229 284 349 258 32 33 146 69 226 143 312 48 26 159 235 447 115 59 279 212 162 500 194 413 408 71 249 371 419 25 90 204 180 108 262 414 363 99 295 319 345 236 409 14 52 278 387 294 445 432 47 360 471 465 224 43 107 232 266 316 428 372 404 34 160 64 130 493 223 359 396 373 176 220 230 184 430 339 281 285 427 264 275 95 334 495 193 267 80 486 380 238 5 148 395 23 397 37 472 351 141 241 244 365 196 423 126 494 341 347 467 187 424 490 135 57 326 411 111 459 10 61 13 394 268 452 134 39 338 261 389 310 139 378 114 406 228 364 449 318 29 252 417 181 382 22 337 144 203 113 161 125 481 323 35 354 207 478 302 361 12 167 217 20 383 379 276 155 83 274 202 190 488 418 385 185 67 307 120 172 31 308 9 211 58 289 374 98 496 290 157 104 454 491 60 183 433 296 444 56 443 254 277 343 169 51 483 272 498 366 227 89 239 477 362 416 451 210 70 38 209 206 75 119 425 74 208 356 358 407 291 344 41 482 24 370 85 171 321 19 192 165 81 101 173 357 121 270 435 499 456 2 27 250 317 237 93 112 15 263 234 431 150 367 78 140 136 331 292 453 116 1 376 129 21 415 219 315 216 102 96 336 346 82 6 421 251 434 484 440 137 446 298 306 233 422 448 245 470 188 426 151 464 388 44 225 460 287 123 476 97 492 282 106 497 259 283 324 45 442 311 131 17 485 429 198 195 174 469 350 11 475 487 4 348 466 68 260 103 437 480 420 474 178 405 128 246 50 243 40 253 110 18 73 455 163 248 369 205 305 412 182 124 158 300 375 403 457 439 142 55 381 79 65 320 46 213 16 179 66 132 333 189 122 84 152 30 286 269 288 304 145 265 463 353 3 147 94 86 133 62 154 49 436 410 200 313 247 325 240 201 255 392 450 458 109 100 197 92"};
	//char *s[2] = {"name", "177 128 107 109 452 352 388 305 398 47 445 455 432 207 473 56 263 402 283 261 425 374 253 21 301 44 351 94 110 1 297 490 242 485 321 285 406 176 288 375 238 168 488 147 391 255 202 356 236 93 365 154 140 116 309 152 495 281 336 340 170 229 487 324 61 148 273 212 413 492 120 341 188 456 43 225 442 77 58 267 119 130 429 133 78 385 400 55 173 9 183 479 320 195 71 99 491 100 275 4 325 454 404 194 434 12 150 287 303 103 151 441 42 412 451 59 45 146 483 230 382 243 218 49 378 469 101 423 161 8 422 143 190 419 256 323 254 467 271 111 332 415 221 405 337 427 364 23 203 104 347 169 420 214 444 304 6 435 64 144 48 395 310 22 204 368 346 81 449 249 28 252 313 383 178 95 493 79 65 379 199 134 132 453 34 117 463 62 328 157 344 496 247 220 74 268 440 499 67 66 106 76 237 5 439 118 446 428 222 97 389 223 465 13 421 294 307 41 30 477 399 339 450 232 185 20 216 437 187 68 136 248 228 192 298 289 355 57 300 460 52 60 342 127 338 319 358 369 122 139 371 171 27 142 26 362 193 89 436 227 482 270 333 239 137 359 269 50 96 284 360 266 327 366 484 153 234 16 233 72 138 179 343 277 15 312 299 102 113 155 409 272 497 85 80 367 416 172 471 32 414 486 481 205 3 258 390 54 209 211 53 36 306 424 480 149 474 478 353 257 241 278 19 394 156 430 354 457 165 286 38 219 279 182 431 29 331 11 345 260 37 88 123 51 280 466 90 259 135 82 175 262 167 476 40 114 7 315 361 475 408 87 448 231 296 83 141 124 393 201 407 174 274 384 350 373 181 166 108 91 357 426 73 292 86 121 84 443 159 196 25 31 112 464 215 308 251 164 459 198 200 46 387 489 397 293 372 250 160 282 265 392 115 401 98 163 131 468 245 197 326 322 235 240 291 180 206 69 494 226 14 186 208 410 302 33 470 418 18 39 376 295 370 276 386 75 70 458 335 447 461 498 290 126 438 210 35 92 363 2 213 472 411 24 316 191 244 349 500 145 433 314 189 380 184 381 224 318 377 317 217 10 334 396 158 246 125 330 403 329 348 311 129 462 264 63 162 17 105 417"};
	//char *s[2] = {"name", "120 147 330 67 11 278 32 442 253 39 51 396 353 229 207 94 170 258 302 144 404 231 222 405 235 135 382 301 282 284 319 443 230 116 139 125 355 350 438 248 239 386 488 81 186 141 55 97 16 262 272 335 439 313 403 129 285 432 290 434 42 383 124 19 491 312 363 153 444 17 472 280 461 437 85 249 104 478 157 191 180 489 445 72 408 402 15 205 88 266 377 252 64 375 47 451 195 393 25 159 428 113 374 275 56 172 121 373 58 340 82 483 202 348 76 112 132 486 196 448 177 354 337 423 372 392 500 161 492 79 297 482 99 457 292 133 49 122 80 1 217 43 181 409 435 365 90 200 189 236 490 397 37 391 362 26 110 78 77 244 419 163 333 238 89 447 10 65 314 193 309 34 106 331 102 7 276 166 226 265 289 291 114 384 359 345 495 430 311 339 31 29 103 498 484 413 183 182 462 96 426 61 475 227 137 216 12 98 93 356 257 433 303 6 263 367 140 142 101 83 304 206 417 329 455 30 394 390 59 395 107 328 41 118 134 317 188 268 219 46 400 352 469 497 165 254 175 318 62 369 44 179 474 255 208 287 387 228 270 105 277 187 115 264 150 146 156 127 459 476 454 218 477 209 123 143 349 3 234 320 406 267 310 446 269 458 371 473 422 281 381 171 151 66 288 35 247 38 378 33 410 138 63 48 136 232 250 210 154 456 95 14 243 334 224 336 463 453 440 466 368 178 237 131 468 233 441 54 332 251 344 40 174 245 470 22 9 346 27 283 152 351 294 411 190 192 271 70 24 259 274 57 479 415 360 273 71 385 211 60 465 293 316 158 36 412 358 185 322 421 148 162 242 418 436 13 240 108 86 155 460 493 111 431 338 306 160 167 256 28 452 117 366 246 225 199 425 212 325 315 389 8 201 398 364 69 50 215 376 73 298 420 357 494 307 204 300 91 370 295 2 168 75 286 149 427 92 52 496 261 380 23 221 20 485 130 173 416 342 223 467 198 260 203 176 109 361 326 343 414 84 53 87 327 197 424 126 119 4 21 214 164 220 471 464 429 388 213 145 45 323 128 401 481 194 184 480 321 341 241 169 308 18 347 487 299 379 449 279 407 68 5 450 399 499 324 74 296 100 305"};
	//char *s[2] = {"name", "60 172 233 430 53 441 7 134 324 307 153 205 224 33 225 62 367 390 469 364 495 412 121 8 262 178 475 190 277 281 61 213 218 179 200 117 459 97 31 23 455 318 447 288 287 87 394 230 341 1 291 411 180 80 460 482 366 234 446 463 409 42 88 89 329 241 148 423 242 471 302 184 199 440 157 439 20 371 317 340 373 326 211 436 4 458 63 376 111 18 55 270 118 389 251 195 214 26 360 296 38 406 272 237 279 283 161 69 408 27 498 95 103 358 37 181 488 402 499 123 468 467 49 383 401 348 46 313 335 345 336 330 149 443 101 320 220 263 5 362 273 186 393 480 268 41 198 79 269 93 380 116 478 448 449 202 47 435 64 407 374 74 255 258 133 308 280 3 399 82 398 493 477 83 119 35 479 9 239 346 377 483 481 404 75 191 456 310 162 257 256 311 249 196 444 386 110 29 168 391 11 496 461 159 420 250 395 385 173 50 176 137 96 76 98 171 141 85 425 158 194 473 142 238 352 476 356 232 492 349 54 24 48 6 56 132 333 419 248 472 282 177 30 229 151 10 260 305 12 219 39 392 72 454 228 321 381 424 351 243 431 246 474 452 91 223 400 451 464 261 453 426 140 206 86 22 416 197 146 221 334 301 278 71 405 368 139 284 485 28 490 338 413 306 59 304 361 491 78 175 160 215 105 497 51 337 465 357 169 94 484 267 236 124 130 347 143 34 240 363 165 19 209 319 77 216 428 68 170 40 66 339 300 187 312 264 182 322 315 125 344 466 99 276 100 212 128 113 494 106 397 204 58 235 226 500 32 442 17 372 147 222 418 44 379 92 259 192 332 470 299 102 359 438 145 429 271 350 487 253 265 309 292 2 16 189 185 155 70 433 437 156 327 67 285 90 382 295 457 154 355 135 208 13 331 432 370 167 396 378 183 314 303 108 450 14 275 36 403 115 163 21 188 120 427 422 375 174 489 462 131 138 43 136 114 112 247 45 388 127 144 410 245 325 415 81 354 109 126 150 316 286 65 129 294 107 365 52 414 166 25 164 298 421 417 445 369 15 152 73 297 227 274 217 353 290 328 266 289 231 193 252 323 486 122 207 384 387 201 104 84 293 342 343 434 57 210 254 244 203"};
	// ------------------------------------------------------------------------------------------------------------------------------------------

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
		to_sort(&stack_a, &stack_b);
	}
	return (0);
}