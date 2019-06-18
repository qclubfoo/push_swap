/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:01:49 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/18 00:03:55 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	char	*str;
	int		err;

	err = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		check_av_new(&a, av, &err) > 0 ? ft_error_msg() : 0;
	else
		check_av(&a, ac, av, &err) > 0 ? ft_error_msg() : 0;
	b.str = (int*)malloc(sizeof(int) * a.len);
	b.len = 0;
	if (check_sort(a, b))
	{
		free(a.str);
		free(b.str);
		exit(0);
	}
	ft_sort(&a, &b);
	int i = 0;
	while (i < a.len)
		printf("%d ", a.str[i++]);
	printf("\n");
}

void	ft_error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
