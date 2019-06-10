/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:22:27 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/10 19:23:28 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int			check_s(char *str_r, char *str, int i, int j)
{
	if (str_r[i + 1] == 'a')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '1';
			return (3);
		}
	}
	else if (str_r[i + 1] == 'b')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '2';
			return (3);
		}
	}
	else if (str_r[i + 1] == 's')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '3';
			return (3);
		}
	}
	return (0);
}

int			check_p(char *str_r, char *str, int i, int j)
{
	if (str_r[i + 1] == 'a')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '4';
			return (3);
		}
	}
	else if (str_r[i + 1] == 'b')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '5';
			return (3);
		}
	}
	return (0);
}

static int	check_rrr(char *str_r, char *str, int i, int j)
{
	if (str_r[i + 2] == 'b')
	{
		if (str_r[i + 3] == '\n')
		{
			str[j] = 'a';
			return (4);
		}
	}
	else if (str_r[i + 2] == 'r')
	{
		if (str_r[i + 3] == '\n')
		{
			str[j] = 'b';
			return (4);
		}
	}
	return (0);
}

static int	check_rr(char *str_r, char *str, int i, int j)
{
	if (str_r[i + 2] == '\n')
	{
		str[j] = '8';
		return (3);
	}
	else if (str_r[i + 2] == 'a')
	{
		if (str_r[i + 3] == '\n')
		{
			str[j] = '9';
			return (4);
		}
	}
	return (check_rrr(str_r, str, i, j));
}

int			check_r(char *str_r, char *str, int i, int j)
{
	if (str_r[i + 1] == 'a')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '6';
			return (3);
		}
	}
	else if (str_r[i + 1] == 'b')
	{
		if (str_r[i + 2] == '\n')
		{
			str[j] = '7';
			return (3);
		}
	}
	else if (str_r[i + 1] == 'r')
		return (check_rr(str_r, str, i, j));
	return (0);
}
