/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:33:50 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/14 22:31:29 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sort(t_list a, t_list b)
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
		return (1);
	return (0);
}
