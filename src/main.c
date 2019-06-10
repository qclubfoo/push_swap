/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:26:13 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/08 23:51:20 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int check_s(char *str_r, char *str, int i, int j)
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

int check_p(char *str_r, char *str, int i, int j)
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

int check_r(char *str_r, char *str, int i, int j)
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
		else if (str_r[i + 2] == 'b')
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
	}
	return (0);
}

char	*check_param(void)
{
	char	*str_r;
	char	*str;
	int		i;
	int		ii;
	int		j;

	str_r = ft_read();
	if (str_r == NULL)
	{
		write(1, "ERR\n", 4);
		exit (0);
	}
	if(!(str = (char*)malloc(sizeof(char) * ft_strlen(str_r))))
		exit (0);
	ft_bzero(str, ft_strlen(str_r) - 1);
	i = 0;
	j = 0;
	while(str_r[i])
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
			free(str);
			str = NULL;
			break ;
		}
		else
			j++;
	}
	return (str);
}
int	main(int ac, char **av)
{
	int		*a;
	int		*b;
	char	*str;
	t_list	*param;
	int		err;

	err = 0;
	a = (int*)malloc(sizeof(int) * (ac - 1));
	b = (int*)malloc(sizeof(int) * (ac - 1));
	if (check_av(ac, av, &err))
	{
		free(a);
		free(b);
		write(2, "ERR\n", 4);
		return (0);
	}
	str = check_param();
	if (str == NULL)
	{
		free(str);
		free(a);
		free(b);
		write(2, "ERR\n", 4);
		return (0);
	}
	printf("%s\n", str);
	// write(1, "OK\n", 3);

	// i = ac - 2;
	// while (i >= 0)
	// {
	// 	a[i] = ft_atoi(av[ac-1], &err);
	// 	i--;
	// 	ac--;
	// }
	return (0);
}



