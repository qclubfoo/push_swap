/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:35:44 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/10 16:21:32 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		ft_atoi_err(char *str, int *err)
{
	unsigned long int	res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	*str == '-' ? sign = -1 : 0;
	*str == '+' || *str == '-' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
	{
		if ((res > MAX_I) || ((res == MAX_I && (*str - '0') > 7) && sign == 1)
		|| (res > MAX_I) || ((res == MAX_I && (*str - '0') > 8) && sign == -1))
		{
			*err = 1;
			return (-1);
		}
		res = 10 * res + (int)(*str - '0');
		str++;
	}
	if ((*str > 32 && *str < 48) || (*str > 57 && *str < 127))
		*err = 1;
	return ((int)(sign * res));
}

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

int		ft_err(int **stack)
{
	free(*stack);
	*stack = NULL;
	return (1);
}

void	check_repeat(int *stack, int i, int *err)
{
	int	ii;

	ii = i - 1;
	while (ii >= 0)
	{
		if (stack[ii] == stack[i])
		{
			*err = 1;
			break ;
		}
		ii--;
	}
}

int check_av(int ac, char **av, int *err)
{
	int	*stack;
	int	i;
	int	ii;

	stack = (int*)malloc(sizeof(int) * (ac - 1));
	i = 0;
	ac--;
	while (ac > 0)
	{
		if (*err != 0)
			break ;
		stack[i] = ft_atoi_err(av[ac], err);
		if (i > 0)
			check_repeat(stack, i, err);
		i++;
		ac--;
	}
	if (*err != 0)
		return (ft_err(&stack));
	free(stack);
	stack = NULL;
	return (0);
}
