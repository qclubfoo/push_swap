/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:31:26 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/07 12:21:13 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static t_list	*lst_new(void)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->len = 0;
	new->str = (char*)malloc(sizeof(char) * SIZE + 1);
	new->str[SIZE] = '\0';
	new->next = NULL;
	return (new);
}

static void		lst_add_end(t_list *head)
{
	t_list	*new;

	while (head->next != NULL)
		head = head->next;
	new = (t_list*)malloc(sizeof(t_list));
	new->len = 0;
	new->str = (char*)malloc(sizeof(char) * SIZE + 1);
	new->str[SIZE] = '\0';
	new->next = NULL;
	head->next = new;
}

static int		ft_strncpy(char *dst, char *src, int i, int n)
{
	int	j;

	j = 0;
	while (j < n)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (n);
}

static int		ft_strnncpy(char *dst, char *src, int i, int n)
{
	int	j;

	j = 0;
	while (j < n)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (n);
}

static void		ft_bzero(char *str)
{
	int	i;

	i = 0;
	while(i <= BUFF_SIZE)
		str[i++] = '\0';
}

t_list			*gnl(void)
{
	t_list	*lst;
	t_list	*head;
	t_list	*del;
	int		re;
	char	buf[BUFF_SIZE + 1];
	int		tmp;
	char	*str;

	ft_bzero(buf);
	re = 0;
	head = lst_new();
	lst = head;
	re = read(0, buf, BUFF_SIZE);
	lst->len += ft_strncpy(lst->str, buf, 0, re);
	ft_bzero(buf);
	re = 0;
	re = read(0, buf, BUFF_SIZE);
	while(re > 0)
	{
		if (lst->len + re < SIZE)
			lst->len += ft_strncpy(lst->str, buf, lst->len, re);
		else
		{
			tmp = SIZE - lst->len;
			lst->len += ft_strncpy(lst->str, buf, lst->len, tmp);
			str = (char*)malloc(sizeof(char) * (re - tmp + 1));
			ft_strnncpy(str, buf, tmp, re - tmp);
			lst_add_end(lst);
			lst = lst->next;
			lst->len += ft_strncpy(lst->str, str, lst->len, re - tmp);
			free(str);
			str = NULL;
		}
		re = 0;
		ft_bzero(buf);
		re = read(0, buf, BUFF_SIZE);
	}
	lst = NULL;
	return (head);
}
