NAME = checker

SRC = src/ft_atoi_err.c src/ft_bzero.c src/ft_strlen.c src/ft_strncpy.c src/ft_strsplit.c \
src/check_int.c src/check_rules_1.c src/check_rules_2.c src/main.c src/read.c \
src/rules_1.c src/rules_2.c src/rules_3.c src/sort_and_check.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	cp $(NAME) ../

%.o: src/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) ../$(NAME)

re : fclean all