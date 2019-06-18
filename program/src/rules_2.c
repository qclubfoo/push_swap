/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:09:57 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 00:37:01 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_list *a)
{
	int		tmp;
	int		i;

	if (a->len == 0 || a->len == 1)
		return ;
	i = 0;
	tmp = a->str[i];
	while (i < a->len - 1)
	{
		a->str[i] = a->str[i + 1];
		i++;
	}
	a->str[a->len - 1] = tmp;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list *b)
{
	int		tmp;
	int		i;

	if (b->len == 0 || b->len == 1)
		return ;
	i = 0;
	tmp = b->str[i];
	while (i < b->len - 1)
	{
		b->str[i] = b->str[i + 1];
		i++;
	}
	b->str[b->len - 1] = tmp;
	write(1, "rb\n", 3);
}

void	ft_rr(t_list *a, t_list *b)
{
	int		tmp;
	int		i;

	if (a->len == 0 || a->len == 1)
		return ;
	i = 0;
	tmp = a->str[i];
	while (i < a->len - 1)
	{
		a->str[i] = a->str[i + 1];
		i++;
	}
	a->str[a->len - 1] = tmp;
	if (b->len == 0 || b->len == 1)
		return ;
	i = 0;
	tmp = b->str[i];
	while (i < b->len - 1)
	{
		b->str[i] = b->str[i + 1];
		i++;
	}
	b->str[b->len - 1] = tmp;
	write(1, "rr\n", 3);

	// ft_ra(a);
	// ft_rb(b);
}
