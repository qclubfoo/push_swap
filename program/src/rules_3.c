/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:30:03 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/17 16:14:45 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rra(t_list *a)
{
	int		tmp;
	int		i;

	if (a->len == 0 || a->len == 1)
		return ;
	i = a->len - 2;
	tmp = a->str[a->len - 1];
	while (i >= 0)
	{
		a->str[i + 1] = a->str[i];
		i--;
	}
	a->str[0] = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list *b)
{
	int		tmp;
	int		i;

	if (b->len == 0 || b->len == 1)
		return ;
	i = b->len - 2;
	tmp = b->str[b->len - 1];
	while (i >= 0)
	{
		b->str[i + 1] = b->str[i];
		i--;
	}
	b->str[0] = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list *a, t_list *b)
{
	ft_rra(a);
	ft_rrb(b);
}
