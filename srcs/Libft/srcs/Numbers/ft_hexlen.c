/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:08:54 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:04:28 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_hexlen(unsigned int n)
{
	size_t length;

	length = 0;
	if (n == 0)
		length++;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}
