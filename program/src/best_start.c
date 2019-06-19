/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:40:49 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 10:55:19 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		find_best_start(t_list a, t_max_len *max, int *i)
{
	int			tmp_i;
	int			tmp_len;

	tmp_len = 0;
	tmp_i = *i;
	tmp_len = 1;
	*i += 1;
	while (*i < a.len - 1 && a.str[*i] < a.str[*i + 1])
	{
		*i += 1;
		tmp_len++;
	}
	if (tmp_len > max->length)
	{
		max->index = tmp_i;
		max->length = tmp_len;
	}
}

t_max_len	ft_max_len(t_list a)
{
	int			i;
	t_max_len	max;

	i = 0;
	max.index = 0;
	max.length = 0;
	while (i < a.len - 1)
	{
		if (a.str[i] < a.str[i + 1])
			find_best_start(a, &max, &i);
		else
			i++;
	}
	return (max);
}

void		make_best_start(t_list *a, t_list *b, t_max_len max)
{
	int i;

	if (max.length > 3)
	{
		i = 0;
		while (i++ != max.index)
			ft_pb(a, b);
		while (i++ <= max.length + max.index)
			ft_ra(a);
		while (a->len > max.length)
			ft_pb(a, b);
	}
	else
	{
		while (a->len > 3)
			ft_pb(a, b);
		sort_three(a);
	}
}

void		sort_three(t_list *a)
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

void		ft_check_best_pos(t_list *a, t_list *b, t_min *min, int i)
{
	int		ud_b;
	int		ud_a;
	int		total;

	while (++i < b->len)
	{
		ud_b = up_or_down_b(*b, b->str[i]);
		ud_a = up_or_down_a(*a, b->str[i]);
		total = ud_a;
		if (ud_b < 0 && ud_a < 0)
			total = (ud_b < ud_a ? -ud_b : -ud_a);
		else if (ud_b > 0 && ud_a > 0)
			total = (ud_b > ud_a ? ud_b : ud_a);
		else
			total = (total < 0 ? -total : total) + (ud_b < 0 ? -ud_b : ud_b);
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
