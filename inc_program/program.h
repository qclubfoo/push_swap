#ifndef PROGRAM_H
# define PROGRAM_H

# define MAX_I 214748364
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int		min;
	int		len;
	int		*str;
}	t_list;

int		ft_atoi_err(char *str, int *err);
int		ft_atoi(char *str);

int     check_av(int ac, char **av, int *err);
void    ft_sort_poor(t_list *a, t_list *b);
void	ft_find_min(t_list *stack);
int		rotate_only(t_list *a, t_list *b);
void	make_rotate(t_list *a);


#endif
