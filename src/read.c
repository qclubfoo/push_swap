/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:14:01 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/08 23:47:27 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		ft_bzero(char *str, int len)
{
	int	i;

	if (len < 0)
		return ;
	i = 0;
	while(i <= len)
		str[i++] = '\0';
}

int		ft_strncpy(char *dst, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i);
}

int		ft_strlen(char *str)
{
	if (str == NULL)
		return (-1);
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_realloc(char *str, int re)
{
	char	*tmp;
	int		len;

	if (str == NULL)
	{
		if (!(str = (char*)malloc(sizeof(char) * (re + 1))))
			exit (0);
		str[re + 1] = '\0';
		return (str);
	}
	len = ft_strlen(str);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + re + 1))))
		exit (0);
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
