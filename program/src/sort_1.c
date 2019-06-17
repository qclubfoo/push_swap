/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 23:38:19 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/15 18:34:19 by qclubfoo         ###   ########.fr       */
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

int		up_or_down_min(t_list b, int min)
{
	int		i;

	i = 0;
	while (b.str[i] != min)
		i++;
	if (i <= b.len - i)
		return (i + 2);
	else
		return (-(b.len - i) - 2);
}

int		up_or_down_max(t_list b, int max)
{
	int		i;

	i = 0;
	while (b.str[i] != max)
		i++;
	if (i <= b.len - i)
		return (i);
	else
		return (-(b.len - i));
}

int		cmp_ud(int ud_max, int ud_min)
{
	int	cmp;

	ud_max < 0 ? ud_max = -ud_max : 0;
	ud_min < 0 ? ud_min = -ud_min : 0;
	cmp = ud_max - ud_min;
	if (cmp > 0)
		return (0);
	else
		return (1);
}

void	make_min(t_list *a, t_list *b, int count)
{
	count < 0 ? count += 2 : 0;
	count > 0 ? count -= 2 : 0;
	while (count < 0)
	{
		ft_rrb(b);
		count++;
	}
	while (count > 0)
	{
		ft_rb(b);
		count--;
	}
	ft_pa(a, b);
	ft_ra(a);
}

void	make_max(t_list *a, t_list *b, int count)
{
	while (count < 0)
	{
		ft_rrb(b);
		count++;
	}
	while (count > 0)
	{
		ft_rb(b);
		count--;
	}
	ft_pa(a, b);
}

void	last_sort(t_list *a, int count)
{
	while (count < 0)
	{
		ft_rra(a);
		count++;
	}
	while (count > 0)
	{
		ft_ra(a);
		count--;
	}
}

void	ft_sort(t_list *a, t_list *b)
{
	int	max;
	int	min;
	int	ud_max;
	int	ud_min;
	int	i;

	max = ft_find_max(*a);
	while (a->len > 1)
	{
		if (a->str[0] == max)
			ft_ra(a);
		ft_pb(a, b);
	}
	// 	printf("stack a: ");
	// while (i < a->len - 1)
	// 	printf("%d ", a->str[i++]);
	// if (a->len >= 1)
	// 	printf("%d\n", a->str[i]);
	// i = 0;
	// printf("stack b: ");
	// while (i < b->len - 1)
	// 	printf("%d ", b->str[i++]);
	// if (b->len >= 1)
	// 	printf("%d\n", b->str[i]);
	while (b->len > 0)
	{
		max = ft_find_max(*b);
		min = ft_find_min(*b);
		ud_max = up_or_down_max(*b, max);
		ud_min = up_or_down_min(*b, min);
		// printf("max = %d\nmin = %d\n", max, min);
		if (cmp_ud(ud_max, ud_min))
			make_max(a, b, ud_max);
		else
			make_min(a, b, ud_min);
		// i = 0;
		// printf("stack a: ");
		// while (i < a->len - 1)
		// 	printf("%d ", a->str[i++]);
		// if (a->len >= 1)
		// 	printf("%d\n", a->str[i]);
		// i = 0;
		// printf("stack b: ");
		// while (i < b->len - 1)
		// 	printf("%d ", b->str[i++]);
		// if (b->len >= 1)
		// 	printf("%d\n", b->str[i]);
	}
	min = ft_find_min(*a);
	ud_min = up_or_down_max(*a, min);
	last_sort(a, ud_min);
}
