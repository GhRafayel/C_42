# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rghazary <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:39:24 by rghazary          #+#    #+#              #
#    Updated: 2024/10/30 12:39:27 by rghazary         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = checker.c ../../get_next_line/get_next_line.c ../../get_next_line/get_next_line_utils.c \
		../stack_fun.c ../push_swap_utils.c

CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = checker_Mac
LIBC = ar rcs
OBJS = $(SRCS:.c=.o)

LIBFT = ../../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PUSH_SWAP) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
