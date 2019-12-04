/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 23:33:43 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/libftprintf.h"

int	per_d(va_list va, t_param *p)
{
	unsigned int	n_print;
	long			nbr;
	int				padding;
	int				i;

	i = 0;
	n_print = 0;
	
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	nbr = va_arg(va, int);
	padding = ft_ilen(nbr) + p->show_sign + ((nbr >= 0) * p->is_sp_pref) + (nbr < 0);
	if (p->precision)
	{
		p->prefix = ' ';
		n_print += disp_justif(ft_abs(p->min_width - p->precision), p, 0);
	} 
	else if (ft_ilen(nbr) < p->min_width)
	{	
		p->prefix = ' ';
		n_print += disp_justif(p->min_width - padding, p, 0);
	} else
		n_print += disp_justif(p->min_width - padding, p, 0);

	if (p->show_sign || nbr < 0)
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-'));
	if (p->is_sp_pref && nbr >= 0)
		n_print += write(1, " ", 1);
	if ((p->precision && !p->left_justif))
		while ((i < ft_abs(p->precision - p->min_width) - padding))
		{
			n_print += write(1, "0", 1);
			i++;
		}
	ft_putnbr_fd(ft_abs(nbr), 1);
	n_print += ft_ilen(nbr) + (nbr < 0 || p->show_sign);
	if (p->precision)
		n_print += disp_justif(ft_abs(p->precision - p->min_width), p, 1);
	else
		n_print += disp_justif(p->min_width - padding, p, 1);
	return (n_print);
}