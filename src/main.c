/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:26:13 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/10 16:47:46 by qclubfoo         ###   ########.fr       */
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
		write(2, "Error\n", 6);
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

void		ft_checker(int ac, char **av, char *str)
{	
	t_list	a;
	t_list	b;
	int		i;

	i = 0;
	a.str = (int*)malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		a.str[i] = ft_atoi(av[i + 1]);
		i++;
	}
	a.len = ac - 1;
	i = 0;
	b.str = (int*)malloc(sizeof(int) * (ac - 1));
	b.len = 0;
	while (*str)
	{
		if (*str == '1')
			ft_sa(&a);
		else if (*str == '2')
			ft_sb(&b);
		else if (*str == '3')
			ft_ss(&a, &b);
		else if (*str == '4')
			ft_pa(&a, &b);
		else if (*str == '5')
			ft_pb(&a, &b);
		else if (*str == '6')
			ft_ra(&a);
		else if (*str == '7')
			ft_rb(&b);
		else if (*str == '8')
			ft_rr(&a, &b);
		else if (*str == '9')
			ft_rra(&a);
		else if (*str == 'a')
			ft_rrb(&b);
		else if (*str == 'b')
			ft_rrr(&a, &b);
		str += 1;		
	}
	check_sort(a, b);
	free(a.str);
	free(b.str);
}

int	main(int ac, char **av)
{
	char	*str;
	int		err;

	if (ac == 1)
		return (0);
	err = 0;
	if (check_av(ac, av, &err))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	str = check_param();
	if (str == NULL)
	{
		free(str);
		write(2, "Error\n", 6);
		exit (0);
	}
	ft_checker(ac, av, str);
	exit (0);
}



