/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:19:46 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:01:54 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_putunbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
