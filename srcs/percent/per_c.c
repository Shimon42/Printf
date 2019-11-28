/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_c.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 17:46:45 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/libftprintf.h"

int	per_c(va_list va, t_param *p)
{
	unsigned int	n_print;

	n_print = 1;
	n_print += disp_justif(p->justif - 1, p->justif, 0);
	ft_putchar(va_arg(va, int));
	n_print += disp_justif(p->justif + 1, p->justif, 1);
	return (n_print);
}