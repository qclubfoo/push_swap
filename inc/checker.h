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
int		ft_strncpy(char *dst, char *src, int i);
int		ft_strlen(char *str);
void	ft_bzero(char *str, int len);
int		ft_atoi(char *str);

void	check_sort(t_list a, t_list b);
int     check_av(int ac, char **av, int *err);
char	*ft_read(void);

void	ft_sort(char *str, t_list *a, t_list *b);
void	ft_checker(char *str, t_list *a, t_list *b);
int		check_s(char *str_r, char *str, int i, int j);
int		check_p(char *str_r, char *str, int i, int j);
int		check_r(char *str_r, char *str, int i, int j);
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

#endif
