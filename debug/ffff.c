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
	return (res - 1);
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

int	fount_biggist(t_stack **stack)
{
	int			num;
	int			i;
	t_stack		*pnt;

	pnt = (*stack);
	num = pnt -> val;
	i = 0;
	while (pnt)
	{
		if(pnt -> val > num)
		{
			num = pnt -> val;
		}
		pnt = pnt -> next;
	}
	pnt = (*stack);
	while (pnt)
	{
		if(pnt -> val == num)
			break;
		pnt = pnt -> next;
		i++;
	}
	return (i);
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

int les_num(t_stack **stack)
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

int	found_mite(t_stack **stack, int n )
{
	 int mit;
	 int j;

	 mit = les_num(stack);
	 j = 0;
	while (n > j)
	{
		mit = to_mite(stack, mit);
		j++;
	}
	return (mit);
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
		else if ((*stack_a) -> val > (*stack_a) -> next -> val)
		{
			sa_sb(stack_a, 'a');
				i+=1;
		}
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

int foo1(t_stack **stack_a, t_stack **stack_b, int center, int n)
{
	int i;

	i = 0;
	while (n && stack_size(*stack_a) > 1)
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

int foo2(t_stack **stack_a, t_stack **stack_b)
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
			if (fount_biggist(stack_b) > stack_size(*stack_b) / 2)
			{
				rra_rrb(stack_b, 'b');
				i++;
				print_stack(*stack_a, *stack_b);
				
			}
			else
			{
				ra_rb(stack_b, 'b');
				i++;
				print_stack(*stack_a, *stack_b);
			}
		}
		else
		{
			pa_pb(stack_a, stack_b, 'a');
			print_stack(*stack_a, *stack_b);
			s_len--;
			i++;
		}
	}
	return (i);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int len;
	int i;
	int n;
	i = 0;
	n = 2;
	len = stack_size(*stack_a);
	n = len / 5;
	if (len >= 500)
		n = len / 7;
	while (stack_size(*stack_a) > 1)
	{
		i += foo1(stack_a, stack_b, found_mite(stack_a, n), n);
	}
	i += foo2(stack_a, stack_b);
	pa_pb(stack_a, stack_b, 'a');
	printf(" count %d\n", i + 1);
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
	char *s[2] = {"name", "515 694 28 695 396 14 609 11 709 591 330 848 779 248 402 978 339 249 190 202 840 114 61 719 643 221 618 397 565 774 407 288 191 493 340 859 73 545 421 64 426 199 825 356 2 80 718 856 436 775"};
	// 50
	//char *s[2] = {"name", "38 46 6 10 44 3 1 25 5 26 9 12 20 50 17 47 42 49 29 48 35 28 16 21 14 2 40 13 41 11 4 37 36 8 39 18 7 27 24 34 23 22 32 31 33 45 19 43 30 15"};
	//100
	//char *s[2] = {"name", " 520 798 535 830 418 491 293 539 516 541 39 902 597 955 776 93 325 346 569 901 550 182 29 666 771 34 284 845 245 315 797 291 615 607 350 301 188 393 316 857 696 163 142 888 907 490 243 950 36 119 770 694 152 719 486 274 86 381 307 364 237 611 462 908 992 103 858 408 778 154 764 851 925 445 347 859 681 949 52 205 502 635 575 866 718 686 675 53 732 821 328 456 10 416 722 932 324 874 426 352"};
	//char *s[2] = {"name", " 98 -18 87 40 50 -38 2 65 4 -71 -31 92 -9 -81 21 84 1 11 -90 78 25 42 -56 62 -39 85 52 -93 37 -94 96 -50 -86 -63 -95 -2 -57 34 32 66 41 15 -51 64 -49 72 88 59 -8 99 80 -22 47 95 69 -92 -13 3 35 -41 73 17 -58 10 -52 27 97 31 60 28 -83 -20 -68 -1 79 75 22 89 -69 -19 -24 83 -75 -96 -34 -25 -80 -59 -77 -36 57 82 38 18 -27 -12 -60 5 14 33"};
	// 100
	//char *s[2] = {"name", " 20 53 49 24 10 99 39 83 41 58 92 68 93 97 7 96 45 22 86 85 87 98 32 30 63 60 61 9 89 81 69 8 50 21 27 59 84 95 5 14 90 57 40 3 4 82 2 44 6 33 52 55 91 56 79 35 72 31 18 13 70 80 48 88 42 47 65 64 51 78 26 34 94 36 46 19 38 25 12 28 37 77 100 62 76 11 43 73 74 67 17 54 1 66 29 71 15 23 75 16"};
	// 500
	//char *s[2] = {"name", " 48 374 329 255 464 470 139 462 348 258 261 285 1 448 500 488 160 305 79 442 128 310 177 235 386 469 418 472 118 186 7 219 420 431 484 269 230 253 314 104 125 363 157 215 440 145 421 155 92 75 391 313 434 66 244 73 334 282 212 202 120 371 328 456 445 430 74 146 251 354 173 54 223 227 55 148 229 149 188 184 30 326 224 491 249 267 276 379 446 195 182 260 187 44 350 37 427 152 90 17 358 486 325 299 444 268 113 33 214 26 319 412 78 138 53 96 124 89 479 302 408 284 409 473 107 298 190 23 492 466 192 264 199 336 106 312 480 97 388 88 198 169 375 300 324 112 232 315 435 352 3 165 175 356 303 364 210 216 438 211 225 94 87 458 72 218 309 115 404 341 366 207 68 65 12 392 414 162 27 130 39 263 376 459 335 80 361 221 110 19 9 372 400 147 277 21 482 317 259 321 494 183 123 461 57 67 83 208 405 242 327 2 452 330 93 28 14 396 233 122 307 105 111 387 45 209 429 443 339 135 389 398 407 489 301 415 10 129 422 220 347 154 416 20 178 81 271 410 487 121 294 426 29 250 161 394 266 85 287 38 98 15 84 151 485 246 59 46 240 43 108 402 370 275 380 278 62 403 468 167 477 238 136 495 150 201 467 13 174 323 159 453 355 181 248 357 308 6 460 292 158 126 95 204 481 114 236 295 423 318 116 322 385 206 413 498 252 18 497 56 86 51 393 205 411 153 109 134 270 197 237 306 281 70 127 390 141 156 166 441 383 406 176 359 194 377 286 180 36 351 365 265 360 99 247 425 142 239 463 189 450 213 337 144 476 490 320 274 101 254 163 449 226 69 31 191 77 171 279 293 179 296 289 140 193 76 11 471 436 133 256 273 50 369 102 419 137 367 433 4 25 333 231 34 381 8 397 203 311 228 316 170 342 344 475 119 103 100 40 362 63 117 496 16 82 234 332 447 291 49 283 71 5 353 290 61 143 24 349 164 499 346 343 457 222 465 493 42 35 131 373 382 474 483 132 185 428 217 243 257 288 280 60 297 262 32 91 401 58 41 47 417 22 345 439 432 241 200 454 64 384 52 340 368 478 272 168 455 331 399 196 378 338 437 304 424 172 395 "};
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