/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 21:13:00 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/libftprintf.h"

void	gest_sign_pref(t_param *p, int nbr, int *n_print)
{
	if (p->show_sign || nbr < 0)
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-'));
	if (p->is_sp_pref && nbr >= 0)
		*n_print += write(1, " ", 1);
}

int	per_d(va_list va, t_param *p)
{
	long			nbr;
	int				padding;
	int				i;

	i = 0;
	p->n_print = 0;
	
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	nbr = va_arg(va, int);
	padding = ft_ilen(nbr) + p->show_sign + ((nbr >= 0) * p->is_sp_pref) + (nbr < 0);
	if (p->precision >= 0)
	{
	//	p->prefix = ' ';
		disp_justif(ft_abs(p->min_width - p->precision) - ft_ilen(nbr), p, 0);
	} 
	else if (ft_ilen(nbr) < p->min_width && p->prefix == ' ')
	{	
		disp_justif(p->min_width - padding, p, 0);
	} else
		disp_justif(p->min_width - padding, p, 0);
	if ((p->precision > ft_ilen(nbr) && !p->left_justif))
		while ((i < ft_abs(p->precision - p->min_width) - padding))
		{
			p->n_print += write(1, "0", 1);
			i++;
		}
	ft_putnbr_fd(ft_abs(nbr), 1);
	p->n_print += ft_ilen(nbr) + (nbr < 0 || p->show_sign);
	if (p->precision)
		disp_justif(ft_abs(p->precision - p->min_width), p, 1);
	else
		disp_justif(p->min_width - padding, p, 1);
	return (p->n_print);
}