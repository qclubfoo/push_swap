/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:26:13 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/11 15:38:34 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_program/program.h"

void		ft_find_min(t_list *a)
{
	int		i;

	i = 0;
	a->min = a->str[i++];
	while (i < a->len)
	{
		if (a->min > a->str[i])
			a->min = a->str[i];
		i++;
	}
}

void		ft_stack_b(t_list *b, int ac)
{
	if (!(b->str = (int*)malloc(sizeof(int) * (ac - 1))))
		exit(0);
	b->len = 0;
}		

void		ft_stack_a(t_list *a, int ac, char **av)
{
	int		i;

	i = 0;
	if (!(a->str = (int*)malloc(sizeof(int) * (ac - 1))))
		exit(0);
	while (i < ac - 1)
	{
		a->str[i] = ft_atoi(av[i + 1]);
		i++;
	}
	a->len = ac - 1;
}

void	check_sort(t_list a, t_list b)
{
	int		i;

	i = 0;
	while (i < a.len - 1 && a.len > 2)
	{
		if (a.str[i] < a.str[i + 1])
			i++;
		else
			return ;
	}
	exit(0);
}

int			main(int ac, char **av)
{
	int i;
	t_list	a;
	t_list	b;
	int		err;

	if (ac == 1)
		return (0);
	err = 0;
	if (check_av(ac, av, &err))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	ft_stack_a(&a, ac, av);
	ft_stack_b(&b, ac);
	
	// i = 0;
	// printf("a.min = %d\n", a.min);
	// while (i < a.len)
	// {
	// 	printf("a element [%d] = %d\n", i, a.str[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < b.len)
	// {
	// 	printf("b element [%d] = %d\n", i, b.str[i]);
	// 	i++;
	// }
	check_sort(a, b);
	if (rotate_only(&a, &b))
	{
		make_rotate(&a);
		exit(0);
	}
	ft_sort_poor(&a, &b);
	exit(0);
	return (0);
}
