/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:45:07 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/17 16:20:51 by qclubfoo         ###   ########.fr       */
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

void	ft_sort(t_list *a, t_list *b)
{
	sort_three(a);

}
