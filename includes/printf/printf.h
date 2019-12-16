/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 16:49:16 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 23:51:39 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "brain.h"
#include "debug.h"
#include "../libft.h" 

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int		ft_printf(const char *str, ...);

void	new_s_param(t_brain **b, char *key, void (*f)(char *), void *exp);

void	disp_justif(int n, t_param *p, int left_justif);
void	gest_wildcard(va_list va, t_param *p);
void	print_zeros(t_param *p, int len);
void	free_param(t_param *p);
int		check_flags(t_param *p);

int     per_per(va_list va, t_param *p);
int		per_c(va_list va, t_param *p);
int		per_s(va_list va, t_param *p);
int		per_d(va_list va, t_param *p);
int		per_p(va_list va, t_param *p);
int		per_u(va_list va, t_param *p);
int		per_x(va_list va, t_param *p);
//int		per_lu(va_list va, t_param *p);
//int		per_ld(va_list va, t_param *p);
//int		per_o(va_list va, t_param *p);
#endif