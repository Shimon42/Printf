/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:04:03 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:04:05 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (i < n)
			if (((char*)s)[i++] == c)
				return (&((void *)s)[--i]);
	}
	return (NULL);
}
