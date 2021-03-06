/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:07:35 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:03:50 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (i < n)
			((char*)s)[i++] = 0;
	}
	return (s);
}
