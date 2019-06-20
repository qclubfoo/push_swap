/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:35:44 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/20 18:15:13 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		check_av_new(t_list *a, char **av, int *err)
{
	int		i;
	char	**str;
	int		arg_count;

	str = ft_str_split(av[1], ' ');
	arg_count = check_debug(a, str);
	if (!(a->str = (int*)malloc(sizeof(int) * (arg_count - a->debug))))
		exit(0);
	a->len = arg_count - a->debug;
	i = 0;
	while (i < arg_count - a->debug)
	{
		if (*err != 0)
			break ;
		a->str[i] = ft_atoi_err(str[i + a->debug], err);
		if (i > 0)
			check_repeat(a->str, i, err);
		i++;
	}
	ft_free(str);
	if (*err != 0)
		return (ft_err(&a->str));
	return (0);
}

int		check_av(t_list *a, int ac, char **av, int *err)
{
	int	i;

	if (av[0] != NULL && ft_strcmp(av[1], "-v") != 0)
		a->debug = 1;
	else
		a->debug = 0;
	if (!(a->str = (int*)malloc(sizeof(int) * (--ac - a->debug))))
		exit(0);
	a->len = ac - a->debug;
	i = 0;
	while (i < ac - a->debug)
	{
		if (*err != 0)
			break ;
		a->str[i] = ft_atoi_err(av[i + 1 + a->debug], err);
		if (i > 0)
			check_repeat(a->str, i, err);
		i++;
	}
	if (*err != 0)
		return (ft_err(&a->str));
	return (0);
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

int		ft_err(int **stack)
{
	free(*stack);
	*stack = NULL;
	return (1);
}

void	ft_free(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	str[i] = NULL;
	free(str);
	str = NULL;
}
