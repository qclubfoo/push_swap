/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:45:07 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 01:32:32 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

typedef struct	s_max_len
{
	int		index;
	int		length;
}				t_max_len;

t_max_len	ft_max_len(t_list a)
{
	int			i;
	int			tmp_i;
	int			tmp_len;
	t_max_len	max;

	i = 0;
	tmp_len = 0;
	max.index = 0;
	max.length = 0;
	while (i < a.len - 1)
	{
		if (a.str[i] < a.str[i + 1])
		{
			tmp_i = i;
			tmp_len = 1;
			i++;
			while (i < a.len - 1 && a.str[i] < a.str[i + 1])
			{
				i++;
				tmp_len++;
			}
			if (tmp_len > max.length)
			{
				max.index = tmp_i;
				max.length = tmp_len;
			}
		}
		else
			i++;
	}
	// printf("max.len = %d\nmax.index = %d\n", max.length, max.index);
	return (max);
}

void	ft_sort(t_list *a, t_list *b)
{
	t_min		min;
	t_max_len	max;
	int			i;

	max = ft_max_len(*a);
	// printf("max.len = %d\nmax.index = %d\n", max.length, max.index);
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
	// exit(0);
	// while (a->len > 3)
	// 	ft_pb(a, b);
	// sort_three(a);
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
		if (ud_b < 0 && ud_a < 0)
			total = (ud_b < ud_a ? -ud_b : -ud_a);
		else if (ud_b > 0 && ud_a > 0)
			total = (ud_b > ud_a ? ud_b : ud_a);
		else
		{
			if (total < 0)
				total = -total;
			if (ud_b < 0)
				total = total - ud_b;
			else
				total = total + ud_b;
		}
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
	int	i;

	i = 0;
	ud_b = min.ud_b;
	ud_a = min.ud_a;
	if (ud_b < 0 && ud_a < 0)
	{
		while (ud_b + i < 0 && ud_a + i < 0)
		{
			ft_rrr(a, b);
			i++;
		}
		while (ud_b + i < 0)
		{
			ft_rrb(b);
			i++;
		}
		while (ud_a + i < 0)
		{
			ft_rra(a);
			i++;
		}
	}
	else if (ud_b > 0 && ud_a > 0)
	{
		while (ud_b - i > 0 && ud_a - i > 0)
		{
			ft_rr(a, b);
			i++;
		}
		while (ud_b - i > 0)
		{
			ft_rb(b);
			i++;
		}
		while (ud_a - i > 0)
		{
			ft_ra(a);
			i++;
		}
	}
	else
	{
		while (ud_b++ < 0)
			ft_rrb(b);
		while (min.ud_b-- > 0)
			ft_rb(b);
		while (ud_a++ < 0)
			ft_rra(a);
		while (min.ud_a-- > 0)
			ft_ra(a);
	}
	// int j = 0;
	// 	while (j < a->len)
	// 		printf("%d ", a->str[j++]);
	// 	printf("\n");
	// 	j = 0;
	// 	while (j < b->len)
	// 		printf("%d ", b->str[j++]);
	// 	printf("\n");
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
