/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:45:07 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/18 01:14:11 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_find_max(t_list a)
{
	int		max;
	int		i;

	i = 0;
	max = a.str[i];
	while (++i < a.len)
	{
		if (a.str[i] > max)
			max = a.str[i];
	}
	return (max);
}

int		ft_find_min(t_list a)
{
	int		min;
	int		i;

	i = 0;
	min = a.str[i];
	while (++i < a.len)
	{
		if (a.str[i] < min)
			min = a.str[i];
	}
	return (min);
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

int		up_or_down_b(t_list b, int num)
{
	int		i;

	i = 0;
	while (b.str[i] != num)
		i++;
	if (i <= b.len - i)
		return (i);
	else
		return (-(b.len - i));
}

int		up_or_down_a(t_list a, int num)
{
	int	i;

	i = 0;
	while (num > a.str[i] && i < a.len)
	{
		i++;
	}
	if (i <= a.len - i)
		return (i);
	else
		return (-(a.len - i));
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

void	ft_sort(t_list *a, t_list *b)
{
	t_min	min;
	int		ud_b;
	int		ud_a;
	int		total;
	int		i;

	while (a->len > 3)
		ft_pb(a, b);
	sort_three(a);
	// i = -1;
	// while (++i < b->len)
	// 	printf("%d ", b->str[i]);
	// printf("\n");
	while (b->len > 0)
	{
		i = 0;
		min.ud_b = up_or_down_b(*b, b->str[i]);
		min.ud_a = up_or_down_a(*a, b->str[i]);
		min.total = (min.ud_b < 0 ? -min.ud_b : min.ud_b) + (min.ud_a < 0 ? -min.ud_a : min.ud_a);
		// printf("min.b = %d\nmin.a = %d\nmin.total = %d\n", min.ud_b, min.ud_a, min.total);
		while (++i < b->len)
		{
			// printf("i = %d\n", i);
			// printf("fdfdfsf b.str[%d] = %d\n", i, b->str[i]);
			ud_b = up_or_down_b(*b, b->str[i]);
			ud_a = up_or_down_a(*a, b->str[i]);
			total = ud_a;
			if (total < 0)
				total = -total;
			if (ud_b < 0)
				total = total - ud_b;
			else
				total = total + ud_b;
			// printf("ud_b[%d] = %d\nud_a[%d] = %d\ntotal[%d] = %d\n", i, ud_b, i, ud_a, i, total);
			if (total < min.total)
			{
				min.total = total;
				min.ud_b = ud_b;
				min.ud_a = ud_a;
			}
			ud_b = 0;
			ud_a = 0;
			total = 0;
		}
		ft_sort_param(a, b, min);
	}
	// ft_final_sort(a, ft_find_min(*a));
	// while (i < a->len - 1)
	// 	printf("%d ", a->str[i++]);
	// printf("%d\n", a->str[i]);
	// i = 0;
	// while (i < b->len - 1)
	// 	printf("%d ", b->str[i++]);
	// if (b->len >= 1)
	// 	printf("%d\n", b->str[i]);

}
