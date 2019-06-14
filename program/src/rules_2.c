/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:09:57 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/14 22:39:13 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_list *a)
{
	int		tmp;
	int		i;

	if (a->len == 0 || a->len == 1)
		return ;
	else if (a->len == 2)
	{
		ft_sa(a);
		return ;
	}
	i = 0;
	tmp = a->str[i];
	while (i < a->len - 1)
	{
		a->str[i] = a->str[i + 1];
		i++;
	}
	a->str[a->len - 1] = tmp;
}

void	ft_rb(t_list *b)
{
	int		tmp;
	int		i;

	if (b->len == 0 || b->len == 1)
		return ;
	else if (b->len == 2)
	{
		ft_sb(b);
		return ;
	}
	i = 0;
	tmp = b->str[i];
	while (i < b->len - 1)
	{
		b->str[i] = b->str[i + 1];
		i++;
	}
	b->str[b->len - 1] = tmp;
}

void	ft_rr(t_list *a, t_list *b)
{
	ft_ra(a);
	ft_rb(b);
}
