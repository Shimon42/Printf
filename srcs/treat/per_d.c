/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 16:10:20 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/libftprintf.h"

void	gest_sign_pref(t_param *p, int nbr)
{
	
	if (p->show_sign || nbr < 0)
	{
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-'));
		p->n_print++;
	} 
	if (p->is_sp_pref && nbr >= 0 && !p->show_sign)
		p->n_print += write(1, " ", 1);
}

void	gest_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width;
	padding -= (p->is_sp_pref || p->show_sign || nbr < 0);
	if (p->precision > len)
		padding -= p->precision;
	else
		padding -= len;
	if (padding > 0)
	disp_justif(padding, p, 0);
	gest_sign_pref(p, nbr);
	if ((!p->left_justif || p->precision) && (p->precision - len > 0))
		print_zeros(p, p->precision - len);
	ft_putnbr_fd(ft_abs(nbr), 1);
	p->n_print += len;
	disp_justif(padding, p, 1);
}

void	gest_no_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width - len;
	padding -= (p->is_sp_pref || p->show_sign || nbr < 0);
	if (!p->pref_0)
		disp_justif(padding, p, 0);
	gest_sign_pref(p, nbr);
	if (!p->left_justif && p->pref_0)
		print_zeros(p, padding);
	ft_putnbr_fd(ft_abs(nbr), 1);
	p->n_print += len;
	disp_justif(padding, p, 1);
}

int	per_d(va_list va, t_param *p)
{
	long			nbr;
	int				i;

	i = 0;
	p->n_print = 0;
	gest_wildcard(va, p);
	nbr = va_arg(va, int);
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	if (p->precision >= 0)
		gest_precision(p, nbr, ft_ilen(nbr));
	else
		gest_no_precision(p, nbr, ft_ilen(nbr));
	return (p->n_print);
}