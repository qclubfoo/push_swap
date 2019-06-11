/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:24:43 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/11 17:28:24 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_program/program.h"

int		up_or_down(t_list *a)
{
	int	i;
	
	i = 0;
	while (i < a->len)
	{
		if (a->str[i] == a->min)
			break ;
		i++;
	}
	if (i < a->len - i)
		return (i);
	else
		return (-(a->len - i));
}

void	ft_sa(t_list *a)
{
	int		tmp;

	if (a->len > 1)
	{
		tmp = a->str[0];
		a->str[0] = a->str[1];
		a->str[1] = tmp;
	}
}

void	ft_rra(t_list *a, int rep)
{
	int		tmp;
	int		i;

	while (rep > 0)
	{
		if (a->len == 0 || a->len == 1)
			return ;
		else if (a->len == 2)
		{
			ft_sa(a);
			write(1, "sa\n", 3);
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
		rep--;
		write(1, "rra\n", 4);
	}
}

void	ft_ra(t_list *a, int rep)
{
	int		tmp;
	int		i;

	while(rep > 0)
	{
		if (a->len == 0 || a->len == 1)
			return ;
		else if (a->len == 2)
		{
			ft_sa(a);
			write(1, "sa\n", 3);
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
		rep--;
		write(1, "ra\n", 3);
	}
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

void	ft_sort_poor(t_list *a, t_list *b)
{
	int		ud;

	while (a->len > 1)
	{
		ft_find_min(a);
		ud = up_or_down(a);
		// printf("ud = %d\n", ud);
		if (ud > 0)
			ft_ra(a, ud);
		else if (ud < 0)
			ft_rra(a, -ud);
		ft_pb(a, b);
	}
	while (b->len > 0)
		ft_pa(a, b);
	ud = 0;
	// while (ud < a->len)
	// 	printf("%d ", a->str[ud++]);
	// printf("\n");
}

void	make_rotate(t_list *a)
{
	int	i;
	int	ud;

	i = 0;
	while (a->str[i] != a->min)
		i++;
	ud = up_or_down(a);
	if (ud > 0)
		ft_ra(a, ud);
	else
		ft_rra(a, -ud);
	exit(0);
}

int		rotate_only(t_list *a, t_list *b)
{
	int		i;
	int		max;
	int		pos;

	i = 0;
	ft_find_min(a);
	max = a->min;
	// printf("max = %d\nmin = %d\n", max, a->min);
	while (a->str[i] != a->min)
		i++;
	if (i == 0)
		return (0);
	pos = i;
	// printf ("pos = %d\na->len = %d", pos, a->len);
	i++;
	while (i < a->len)
	{
		if (a->str[i] > max)
			max = a->str[i];
		else
			return (0);
		i++;
	}
	// printf("after while max = %d", max);
	i = 0;
	while (i < pos)
	{
		if (a->str[i] > max)
			max = a->str[i];
		else
			return (0);
		i++;
	}
	return (1);
}