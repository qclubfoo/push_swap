/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:14:01 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/10 18:20:49 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

char	*ft_realloc(char *str, int re)
{
	char	*tmp;
	int		len;

	if (str == NULL)
	{
		if (!(str = (char*)malloc(sizeof(char) * (re + 1))))
			exit(0);
		str[re + 1] = '\0';
		return (str);
	}
	len = ft_strlen(str);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + re + 1))))
		exit(0);
	ft_bzero(tmp, len + re);
	ft_strncpy(tmp, str, 0);
	free(str);
	return (tmp);
}

char	*ft_read(void)
{
	char	*str;
	char	buf[101];
	int		re;
	int		i;

	re = 0;
	i = 0;
	ft_bzero(buf, BUFF_SIZE);
	str = NULL;
	while ((re = read(0, buf, BUFF_SIZE)) > 0)
	{
		str = ft_realloc(str, re);
		i = ft_strncpy(str, buf, i);
		ft_bzero(buf, BUFF_SIZE);
		re = 0;
	}
	return (str);
}
