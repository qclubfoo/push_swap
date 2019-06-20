NAME_1 = push_swap

NAME_2 = checker

SRC_PUSH_SWAP = program/src/ft_atoi_err.c program/src/ft_strsplit.c program/src/best_start.c program/src/check_int.c \
program/src/find_pos_func.c program/src/main.c program/src/rules_1.c program/src/rules_2.c program/src/rules_3.c \
program/src/sort_2.c program/src/sort_checking.c program/src/ft_strcmp.c program/src/debug_func.c

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

SRC_CHECKER = checker_files/src/ft_atoi_err.c checker_files/src/ft_bzero.c checker_files/src/ft_strlen.c checker_files/src/ft_strncpy.c checker_files/src/ft_strsplit.c \
checker_files/src/check_int.c checker_files/src/check_rules_1.c checker_files/src/check_rules_2.c checker_files/src/main.c checker_files/src/read.c \
checker_files/src/rules_1.c checker_files/src/rules_2.c checker_files/src/rules_3.c checker_files/src/sort_and_check.c

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

all :
	$(MAKE) -C ./program
	$(MAKE) -C ./checker_files

clean :
	rm -f $(OBJ_PUSH_SWAP)
	rm -f $(OBJ_CHECKER)

fclean : clean
	rm -f $(NAME_1)
	rm -f ./program/$(NAME_1)
	rm -f $(NAME_2)
	rm -f ./checker_files/$(NAME_2)

re : fclean all