/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:53:20 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/20 18:16:07 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_debug(t_list a, t_list b)
{
	int	i;

	i = 0;
	read(0, NULL, 1);
	ft_printf(" *  *  *  *  *  *  *  *  * \nStack A: ");
	while (i < a.len)
		ft_printf("%-4d", a.str[i++]);
	i = 0;
	ft_printf("\nStack B: ");
	while (i < b.len)
		ft_printf("%-4d", b.str[i++]);
	ft_printf("\n *  *  *  *  *  *  *  *  * \n");
}

void	print_param(t_list *a, t_list *b, t_min min)
{
	int	ud_b;
	int	ud_a;

	ud_b = min.ud_b;
	ud_a = min.ud_a;
	while (ud_b++ < 0)
	{
		ft_rrb(b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
	while (min.ud_b-- > 0)
	{
		ft_rb(b);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
	while (ud_a++ < 0)
	{
		ft_rra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
	while (min.ud_a-- > 0)
	{
		ft_ra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
}

void	sort_three(t_list *a, t_list *b)
{
	int	max;
	int	min;

	max = ft_find_max(*a);
	min = ft_find_min(*a);
	if (a->str[0] == max)
	{
		ft_ra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
	else if (a->str[1] == max)
	{
		ft_rra(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
	if (a->str[1] == min)
	{
		ft_sa(a);
		a->debug == 1 ? ft_debug(*a, *b) : 0;
	}
}

int		check_debug(t_list *a, char **str)
{
	int arg_count;

	arg_count = 0;
	while (str[arg_count] != NULL)
		arg_count++;
	if (str[0] != NULL && ft_strcmp(str[0], "-v") != 0)
		a->debug = 1;
	else
		a->debug = 0;
	return (arg_count);
}
