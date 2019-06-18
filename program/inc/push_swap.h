#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_I 214748364
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int		len;
	int		*str;
}	t_list;

typedef struct s_listt
{
	int		ud_a;
	int		ud_b;
	int		total;
}	t_min;

int		ft_atoi_err(char *str, int *err);
char	**ft_str_split(char *str, char del);

int		check_av(t_list *a, int ac, char **av, int *err);
int		check_av_new(t_list *a, char **av, int *err);
void	check_repeat(int *stack, int i, int *err);
int		check_sort(t_list a, t_list b);
void	ft_free(char **str);
int		ft_err(int **stack);

void	ft_sort(t_list *a, t_list *b);
void	sort_three(t_list *a);
void	ft_check_best_pos(t_list *a, t_list *b, t_min *min, int i);
void	ft_sort_param(t_list *a, t_list *b, t_min min);
void	last_sort(t_list *a, int count);
void	ft_final_sort(t_list *a, int min);

int		up_or_down_a(t_list a, int num);
int		up_or_down_b(t_list b, int num);
int		ft_find_min(t_list a);
int		ft_find_max(t_list a);

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

void	ft_error_msg(void);

#endif
