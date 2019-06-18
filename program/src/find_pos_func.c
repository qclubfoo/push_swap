/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:09:38 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/18 17:16:37 by qclubfoo         ###   ########.fr       */
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
	int	min;
	int	max;

	min = ft_find_min(a);
	max = ft_find_max(a);
	i = 0;
	while (min != a.str[i])
		i++;
	if (num > min && max > num)
	{
		while (a.str[i] < num)
		{
			i++;
			if (i == a.len)
				i = 0;
		}
	}
	if (i <= a.len - i)
		return (i);
	else
		return (-(a.len - i));
}
