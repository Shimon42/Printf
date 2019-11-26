/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 16:49:16 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 19:51:42 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "brain.h"

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int		ft_printf(const char *str, ...);

void	new_s_param(t_brain **b, char *key, void (*f)(char *), void *exp);

void	disp_justif(int n);

void	per_c(va_list va, t_param *p);
void	per_s(va_list va, t_param *p);
void	per_d(va_list va, t_param *p);
void	per_lu(va_list va, t_param *p);
void	per_ld(va_list va, t_param *p);
void	per_u(va_list va, t_param *p);
void	per_o(va_list va, t_param *p);
void	per_x(va_list va, t_param *p);
#endif