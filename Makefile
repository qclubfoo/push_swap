NAME_1 = push_swap

NAME_2 = checker

SRC_PUSH_SWAP = program/ft_atoi_err.c program/ft_strsplit.c program/src/check_int.c program/src/find_pos_func.c \
program/src/main.c program/src/rules_1.c program/src/rules_2.c program/src/rules_3.c program/src/sort_2.c \
program/src/sort_checking.c

SRC_CHECKER = checker_files/ft_atoi_err.c checker_files/ft_bzero.c checker_files/ft_strlen.c checker_files/ft_strncpy.c checker_files/ft_strsplit.c \
checker_files/src/check_int.c checker_files/src/check_rules_1.c checker_files/src/check_rules_2.c checker_files/src/main.c checker_files/src/read.c \
checker_files/src/rules_1.c checker_files/src/rules_2.c checker_files/src/rules_3.c checker_files/src/sort_and_check.c

OBJ_PUSH_SWAP = ft_atoi_err.o ft_strsplit.o check_int.o find_pos_func.o \
main.o rules_1.o rules_2.o rules_3.o sort_2.o \
sort_checking.o

OBJ_CHECKER = ft_atoi_err.o ft_bzero.o ft_strlen.o ft_strncpy.o ft_strsplit.o \
check_int.o check_rules_1.o check_rules_2.o main.o read.o \
rules_1.o rules_2.o rules_3.o sort_and_check.o
CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME_1) : $(NAME_2)
	$(CC) $(FLAGS) -c $(SRC_PUSH_SWAP)
	$(CC) $(FLAGS) $(OBJ_PUSH_SWAP) -o $(NAME_1)

$(NAME_2) :
	$(CC) $(FLAGS) -c $(SRC_CHECKER)
	$(CC) $(FLAGS) $(OBJ_CHECKER) -o $(NAME_2)

%.o: program/src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

%.o: checker_files/src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

%.o: program/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

%.o: checker_files/src/%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

all : $(NAME_1)

clean :
	@rm -f $(OBJ_CHECKER)
	@rm -f $(OBJ_PUSH_SWAP)

fclean : clean
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)

re : fclean all