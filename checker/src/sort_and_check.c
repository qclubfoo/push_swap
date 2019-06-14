/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:33:50 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/14 22:29:36 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_sort_check(char *str, t_list *a, t_list *b)
{
	if (str != NULL)
	{
		while (*str)
			ft_sort(str++, a, b);
	}
	check_sort(*a, *b);
}

void	ft_sort(char *str, t_list *a, t_list *b)
{
	if (*str == '1')
		ft_sa(a);
	else if (*str == '2')
		ft_sb(b);
	else if (*str == '3')
		ft_ss(a, b);
	else if (*str == '4')
		ft_pa(a, b);
	else if (*str == '5')
		ft_pb(a, b);
	else if (*str == '6')
		ft_ra(a);
	else if (*str == '7')
		ft_rb(b);
	else if (*str == '8')
		ft_rr(a, b);
	else if (*str == '9')
		ft_rra(a);
	else if (*str == 'a')
		ft_rrb(b);
	else if (*str == 'b')
		ft_rrr(a, b);
}

void	check_sort(t_list a, t_list b)
{
	int		i;
	int		err;

	err = b.len;
	i = 0;
	while (i < a.len - 1 && a.len >= 2)
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
