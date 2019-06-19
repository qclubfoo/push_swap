/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:30:24 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 16:28:19 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	ft_free_strs(char **str, char **str_r)
{
	free(*str_r);
	free(*str);
	*str = NULL;
	*str_r = NULL;
}

char		*check_param(void)
{
	char	*str_r;
	char	*str;

	str_r = ft_read();
	if (str_r == NULL)
	{
		free(str_r);
		return (NULL);
	}
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(str_r))))
		exit(0);
	ft_bzero(str, ft_strlen(str_r) - 1);
	make_str(str, str_r);
	return (str);
}

void		make_str(char *str, char *str_r)
{
	int	i;
	int	j;
	int	ii;

	i = 0;
	j = 0;
	while (str_r[i])
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
			ft_free_strs(&str, &str_r);
			ft_error_msg();
			exit(0);
		}
		else
			j++;
	}
	free(str_r);
}
