/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:45:07 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/18 17:13:47 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort(t_list *a, t_list *b)
{
	t_min	min;
	int		i;

	while (a->len > 3)
		ft_pb(a, b);
	sort_three(a);
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
	ft_final_sort(a, ft_find_min(*a));
}

void	sort_three(t_list *a)
{
	int	max;
	int	min;

	max = ft_find_max(*a);
	min = ft_find_min(*a);
	if (a->str[0] == max)
		ft_ra(a);
	else if (a->str[1] == max)
		ft_rra(a);
	if (a->str[1] == min)
		ft_sa(a);
}

void	ft_check_best_pos(t_list *a, t_list *b, t_min *min, int i)
{
	int		ud_b;
	int		ud_a;
	int		total;

	while (++i < b->len)
	{
		ud_b = up_or_down_b(*b, b->str[i]);
		ud_a = up_or_down_a(*a, b->str[i]);
		total = ud_a;
		if (total < 0)
			total = -total;
		if (ud_b < 0)
			total = total - ud_b;
		else
			total = total + ud_b;
		if (total < min->total)
		{
			min->total = total;
			min->ud_b = ud_b;
			min->ud_a = ud_a;
		}
		ud_b = 0;
		ud_a = 0;
		total = 0;
	}
}

void	ft_sort_param(t_list *a, t_list *b, t_min min)
{
	int	ud_b;
	int	ud_a;

	ud_b = min.ud_b;
	ud_a = min.ud_a;
	while (ud_b++ < 0)
		ft_rrb(b);
	while (min.ud_b-- > 0)
		ft_rb(b);
	while (ud_a++ < 0)
		ft_rra(a);
	while (min.ud_a-- > 0)
		ft_ra(a);
	ft_pa(a, b);
}

void	ft_final_sort(t_list *a, int min)
{
	int	i;

	i = up_or_down_a(*a, min);
	while (i > 0)
	{
		ft_ra(a);
		i--;
	}
	while (i < 0)
	{
		ft_rra(a);
		i++;
	}
}
