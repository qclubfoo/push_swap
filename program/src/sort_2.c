/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:03:18 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/20 18:03:50 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_sort(t_list *a, t_list *b)
{
	t_min		min;
	t_max_len	max;
	int			i;

	max = ft_max_len(*a);
	make_best_start(a, b, max);
	while (b->len > 0)
	{
		i = 0;
		min.ud_b = up_or_down_b(*b, b->str[i]);
		min.ud_a = up_or_down_a(*a, b->str[i]);
		min.total = (min.ud_b < 0 ? -min.ud_b : min.ud_b)
						+ (min.ud_a < 0 ? -min.ud_a : min.ud_a);
		ft_check_best_pos(a, b, &min, i);
		ft_sort_param(a, b, min);
	}
	ft_final_sort(a, b, ft_find_min(*a));
}

void		ft_sort_up_both(t_list *a, t_list *b, t_min min)
{
	int	ud_b;
	int	ud_a;
	int	i;

	i = 0;
	ud_b = min.ud_b;
	ud_a = min.ud_a;
	while (ud_b + i < 0 && ud_a + i < 0)
	{
		ft_rrr(a, b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
	while (ud_b + i < 0)
	{
		ft_rrb(b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
	while (ud_a + i < 0)
	{
		ft_rra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
}

void		ft_sort_down_both(t_list *a, t_list *b, t_min min)
{
	int	ud_b;
	int	ud_a;
	int	i;

	i = 0;
	ud_b = min.ud_b;
	ud_a = min.ud_a;
	while (ud_b - i > 0 && ud_a - i > 0)
	{
		ft_rr(a, b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
	while (ud_b - i > 0)
	{
		ft_rb(b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
	while (ud_a - i > 0)
	{
		ft_ra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
}

void		ft_sort_param(t_list *a, t_list *b, t_min min)
{
	int	ud_b;
	int	ud_a;
	int	i;

	i = 0;
	ud_b = min.ud_b;
	ud_a = min.ud_a;
	if (ud_b < 0 && ud_a < 0)
		ft_sort_up_both(a, b, min);
	else if (ud_b > 0 && ud_a > 0)
		ft_sort_down_both(a, b, min);
	else
		print_param(a, b, min);
	ft_pa(a, b);
	a->debug == 1 ? ft_debug(*a, *b) : 0;
}

void		ft_final_sort(t_list *a, t_list *b, int min)
{
	int	i;

	i = up_or_down_a(*a, min);
	while (i > 0)
	{
		ft_ra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i--;
	}
	while (i < 0)
	{
		ft_rra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
		i++;
	}
}
