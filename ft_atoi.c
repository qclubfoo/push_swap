/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:16:16 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/13 17:16:39 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/checker.h"

int		ft_atoi(char *str)
{
	unsigned long int	res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if ((res > MAX_I || (res == MAX_I && (*str - '0') > 7)) &&
				sign == 1)
			return (-1);
		else if ((res > MAX_I || (res == MAX_I && (*str - '0') > 8)) &&
				sign == -1)
			return (0);
		res = 10 * res + (int)(*str - '0');
		str++;
	}
	return ((int)(sign * res));
}
