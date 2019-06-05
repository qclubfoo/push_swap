/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:26:13 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/05 19:07:02 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	main(int ac, char **av)
{
	// int		*a;
	// int		*b;
	// int		i;
	// int		ii;
	int		err;

	err = 0;
	// a = (int*)malloc(sizeof(int) * (ac - 1));
	// b = (int*)malloc(sizeof(int) * (ac - 1));
	if (check_av(ac, av, &err))
		{
			write(2, "Error\n", 6);
			// free(a);
			// free(b);
			return (0);
		}
	// i = ac - 2;
	// while (i >= 0)
	// {
	// 	a[i] = ft_atoi(av[ac-1], &err);
	// 	i--;
	// 	ac--;
	// }
	return (0);
}



