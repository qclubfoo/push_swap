/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qclubfoo <qclubfoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:18:08 by qclubfoo          #+#    #+#             */
/*   Updated: 2019/06/19 13:28:18 by qclubfoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		ft_strncpy(char *dst, char *src, int i)
{
	int	j;

	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i);
}
