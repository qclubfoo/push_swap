NAME = push_swap

SRC = src/ft_atoi_err.c src/ft_strsplit.c src/best_start.c src/check_int.c \
src/find_pos_func.c src/main.c src/rules_1.c src/rules_2.c src/rules_3.c \
src/sort_2.c src/sort_checking.c src/ft_strcmp.c src/debug_func.c

PRINTF = src/libftprintf.a

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(PRINTF) $(OBJ) -o $(NAME)
	cp $(NAME) ../

%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) ../$(NAME)

re : fclean all