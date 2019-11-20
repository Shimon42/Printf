/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 16:49:16 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 22:25:15 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "brain.h"

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int		ft_printf(const char *str, ...);

void	new_s_param(t_brain **b, char *key, void (*f)(char *), void *exp);

char	*per_s_exp(va_list va);
#endif