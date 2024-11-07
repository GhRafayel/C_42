FLAGS = -Wall -Wextra -Werror
CC  = cc
NAME = push_swap

NAME_B = checker

SRC = mondatory/utils.c mondatory/sort_fct_r.c mondatory/sort_fct.c\
		mondatory/main.c mondatory/check_arg.c mondatory/index_pushb.c\
		mondatory/sort_small.c mondatory/util_2.c mondatory/utils_3.c

SRC_B = bonus/checker.c bonus/get_next_line.c bonus/sort_fct_bonus.c\
		bonus/sort_fct_rbonus.c bonus/utils_bonus.c bonus/util_2.c\
		bonus/utils_3.c

OBJ = $(src:.c=.o)

OBJ_B = $(src_b:.c=.o)



all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(SRC_B) $(OBJ_B)
	$(CC) $(FLAGS) $(SRC_B) -o $(NAME_B)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all
	