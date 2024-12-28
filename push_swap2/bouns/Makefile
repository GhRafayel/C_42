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
SRCS = checker.c 


CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = checker
OBJS = $(SRCS:.c=.o)

LIBFT = ../../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
