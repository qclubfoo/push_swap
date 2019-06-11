/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:26:13 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/11 17:17:27 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	make_str(char *str, char *str_r)
{
	int	i;
	int	j;
	int	ii;

	i = 0;
	j = 0;
	while (str_r[i])
	{
		ii = i;
		if (str_r[i] == 's')
			i += check_s(str_r, str, i, j);
		else if (str_r[i] == 'p')
			i += check_p(str_r, str, i, j);
		else if (str_r[i] == 'r')
			i += check_r(str_r, str, i, j);
		if (ii == i)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			j++;
	}
}

char		*check_param(t_list a, t_list b)
{
	char	*str_r;
	char	*str;

	str_r = ft_read();
	if (str_r == NULL)
	{
		check_sort(a, b);
		exit(0);
	}
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(str_r))))
		exit(0);
	ft_bzero(str, ft_strlen(str_r) - 1);
	make_str(str, str_r);
	return (str);
}

void		ft_sort(char *str, t_list *a, t_list *b)
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

void		ft_make_ab(int ac, char **av, t_list *a, t_list *b)
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
	i = 0;
	if (!(b->str = (int*)malloc(sizeof(int) * (ac - 1))))
		exit(0);
	b->len = 0;
}

int			main(int ac, char **av)
{
	char	*str;
	int		err;
	t_list	a;
	t_list	b;

	if (ac == 1)
		return (0);
	err = 0;
	if (check_av(ac, av, &err))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	ft_make_ab(ac, av, &a, &b);
	str = check_param(a, b);
	ft_checker(str, &a, &b);
	exit(0);
}
