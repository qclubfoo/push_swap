/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:24:47 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/20 17:58:44 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_list *a)
{
	int		tmp;

	if (a->len > 1)
	{
		tmp = a->str[0];
		a->str[0] = a->str[1];
		a->str[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *b)
{
	int		tmp;

	if (b->len > 1)
	{
		tmp = b->str[0];
		b->str[0] = b->str[1];
		b->str[1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_list *a, t_list *b)
{
	int		i;

	if (b->len < 1)
		return ;
	i = a->len - 1;
	while (i >= 0)
	{
		a->str[i + 1] = a->str[i];
		i--;
	}
	a->str[0] = b->str[0];
	a->len += 1;
	b->len -= 1;
	if (b->len > 0)
	{
		i = 0;
		while (i < b->len)
		{
			b->str[i] = b->str[i + 1];
			i++;
		}
	}
	else
		b->str[0] = 0;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list *a, t_list *b)
{
	int		i;

	if (a->len < 1)
		return ;
	i = b->len - 1;
	while (i >= 0)
	{
		b->str[i + 1] = b->str[i];
		i--;
	}
	b->str[0] = a->str[0];
	b->len += 1;
	a->len -= 1;
	if (a->len > 0)
	{
		i = 0;
		while (i < a->len)
		{
			a->str[i] = a->str[i + 1];
			i++;
		}
	}
	else
		a->str[0] = 0;
	write(1, "pb\n", 3);
}
