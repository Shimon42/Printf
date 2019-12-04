/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_s.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 22:25:02 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int	per_s(va_list va, t_param *p)
{
	char *str;
	unsigned int	n_print;
	int				i;
	int				padding;
	
	i = 0;
	str = va_arg(va, char *);
	n_print = 0;
	padding = p->min_width - ft_strlen(str);
	if (p->precision)
	{
		n_print += disp_justif(p->min_width - p->precision, p, 0);
		n_print += ft_putnstr(str, p->precision);
		n_print += disp_justif(ft_abs(p->precision - p->min_width), p, 1);
	}
	else
	{
		n_print += disp_justif(padding, p, 0);
		n_print += ft_putnstr(str, padding);
		n_print += disp_justif(padding, p, 1);
	}
	return (n_print);
}