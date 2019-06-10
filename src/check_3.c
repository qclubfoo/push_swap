/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:30:03 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/10 18:13:49 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_rra(t_list *a)
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
	i = a->len - 2;
	tmp = a->str[a->len - 1];
	while (i >= 0)
	{
		a->str[i + 1] = a->str[i];
		i--;
	}
	a->str[0] = tmp;
}

void	ft_rrb(t_list *b)
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
	i = b->len - 2;
	tmp = b->str[b->len - 1];
	while (i >= 0)
	{
		b->str[i + 1] = b->str[i];
		i--;
	}
	b->str[0] = tmp;
}

void	ft_rrr(t_list *a, t_list *b)
{
	ft_rra(a);
	ft_rrb(b);
}

void	check_sort(t_list a, t_list b)
{
	int		i;
	int		err;

	err = b.len;
	i = 0;
	while (i < a.len - 1 && a.len > 2)
	{
		if (a.str[i] < a.str[i + 1])
			i++;
		else
		{
			err = -1;
			break ;
		}
	}
	if (err == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
