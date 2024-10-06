# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: rghazary <marvin@42.fr>                    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2024/09/06 16:51:45 by rghazary          #+#    #+#              #
# #    Updated: 2024/09/06 16:51:49 by rghazary         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME = libft.a
CC = cc
FLAG = -Wall -Wextra -Werror
comp = $(CC) $(FLAG)
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
AR = ar rcs
RM = rm -f 

# all : $(NAME) clean
# 	@$(comp)  main.c $(NAME) -o main.o
# 	@./main.o
	
all : $(NAME)

$(NAME) : $(OBJ)
	@ $(AR) $(NAME) $(OBJ)
	
# %.o : %.c
# 	@$(comp) -c $< -o $@
	
bonus: ${NAME} ${OBJ}
	@${AR} ${NAME} ${OBJ}
clean:
	@$(RM) *.o
fclean: clean
	@$(RM) $(NAME)
	
re : fclean all

.PHONY : all bonus clean fclean re