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
SRCS = push_swap.c  sort_ruls_1.c sort_ruls_2.c push_swap_utils_1.c main.c push_swap_utils_2.c


CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = push_swap
OBJS = $(SRCS:.c=.o)

LIBFT = ../libft/libft.a
FT_PRINT = ../ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(FT_PRINT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
