/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 18:03:29 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft/libft.h"
#include "../../includes/libftprintf.h"

int	per_d(va_list va, t_param *p)
{
	unsigned int	n_print;
	long	nbr;

	n_print = 0;
	nbr = va_arg(va, long);
	n_print += disp_justif(p->justif - ft_ilen(nbr) - p->show_sign, p->justif, 0);
	if (p->show_sign)
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-'));
	ft_putnbr_fd(nbr, 1);
	n_print += ft_ilen(nbr) + (nbr < 0 || p->show_sign);
	n_print += disp_justif(p->justif + ft_ilen(nbr) + p->show_sign, p->justif, 1);
	//printf("printed: %d\n", n_print);
	return (n_print);
}