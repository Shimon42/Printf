/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:01:41 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:07:11 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/printf.h"

int	per_n(va_list va, t_param *p)
{
	int *var;

	p->n_print = 0;
	var = va_arg(va, int*);
	if (!var)
		return (0);
	*var = p->parent->n_print;
	return (0);
}
