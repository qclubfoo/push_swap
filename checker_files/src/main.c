/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:01:49 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 16:36:59 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
	str = check_param();
	ft_sort_check(str, &a, &b);
	free(a.str);
	free(b.str);
	if (str != NULL)
		free(str);
	exit(0);
}

void	ft_error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
