#ifndef CHECKER_H
# define CHECKER_H

# define MAX_I 214748364
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 8
#define BUFF_SIZE 100

typedef struct s_list
{
	int		len;
	int		*str;
}	t_list;

int		ft_atoi_err(char *str, int *err);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_bzero(char *str, int len);

void	check_sort(t_list a, t_list b);
int     check_av(int ac, char **av, int *err);
char	*ft_read(void);

void    ft_sa(t_list *a);
void    ft_sb(t_list *b);
void    ft_ss(t_list *a, t_list *b);
void	ft_pa(t_list *a, t_list *b);
void	ft_pb(t_list *a, t_list *b);
void    ft_ra(t_list *a);
void    ft_rb(t_list *b);
void    ft_rr(t_list *a, t_list *b);
void 	ft_rra(t_list *a);
void 	ft_rrb(t_list *b);
void 	ft_rrr(t_list *a, t_list *b);

// t_list	*gnl(void);

#endif
