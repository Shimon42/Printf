/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 23:49:33 by siferrar    ###    #+. /#+    ###.fr     */
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
	unsigned int	nbr_printed;
	unsigned long	nbr;

	//disp_param(p);
	nbr_printed = 0;
	nbr = va_arg(va, unsigned long);
	nbr_printed = disp_justif(p->justif - ft_ilen(nbr), 1);
	if (p->show_sign)
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-')); 
	ft_putnbr_fd(nbr, 1);
	nbr_printed = disp_justif(p->justif - ft_ilen(nbr), 0);
	printf("nbr_printed: %d\n", nbr_printed);
	return (nbr_printed);
}