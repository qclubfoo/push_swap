/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:05:33 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/20 18:15:44 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_I 214748364
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_list
{
	int			len;
	int			*str;
	int			debug;
}				t_list;

typedef struct	s_max_len
{
	int			index;
	int			length;
}				t_max_len;

typedef struct	s_listt
{
	int			ud_a;
	int			ud_b;
	int			total;
}				t_min;

int				ft_atoi_err(char *str, int *err);
char			**ft_str_split(char *str, char del);
int				ft_strcmp(char *str, char *find);
int				ft_printf(char *str, ...);

void			ft_debug(t_list a, t_list b);
int				check_debug(t_list *a, char **str);
int				check_av(t_list *a, int ac, char **av, int *err);
int				check_av_new(t_list *a, char **av, int *err);
void			check_repeat(int *stack, int i, int *err);
int				check_sort(t_list a, t_list b);
void			ft_free(char **str);
int				ft_err(int **stack);

void			ft_sort(t_list *a, t_list *b);
void			sort_three(t_list *a, t_list *b);
void			ft_check_best_pos(t_list *a, t_list *b, t_min *min, int i);
void			ft_sort_param(t_list *a, t_list *b, t_min min);
void			last_sort(t_list *a, int count);
void			ft_final_sort(t_list *a, t_list *b, int min);
void			print_param(t_list *a, t_list *b, t_min min);

int				up_or_down_a(t_list a, int num);
int				up_or_down_b(t_list b, int num);
int				ft_find_min(t_list a);
int				ft_find_max(t_list a);

void			find_best_start(t_list a, t_max_len *max, int *i);
t_max_len		ft_max_len(t_list a);
void			make_best_start(t_list *a, t_list *b, t_max_len max);

void			ft_sa(t_list *a);
void			ft_sb(t_list *b);
void			ft_ss(t_list *a, t_list *b);
void			ft_pa(t_list *a, t_list *b);
void			ft_pb(t_list *a, t_list *b);
void			ft_ra(t_list *a);
void			ft_rb(t_list *b);
void			ft_rr(t_list *a, t_list *b);
void			ft_rra(t_list *a);
void			ft_rrb(t_list *b);
void			ft_rrr(t_list *a, t_list *b);

void			ft_error_msg(void);

#endif
