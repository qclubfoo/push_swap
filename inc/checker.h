#ifndef CHECKER_H
# define CHECKER_H

# define MAX_I 214748364
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_atoi_err(char *str, int *err);
int		ft_atoi(char *str);
int     check_av(int ac, char **av, int *err);
#endif