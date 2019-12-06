/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 21:53:45 by siferrar    ###    #+. /#+    ###.fr     */
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

void	print_zeros(t_param *p, int len)
{
	if (len > 0)
		while (len--)
		{
			ft_putstr(PINK);
			p->n_print += write(1, "0", 1);
			ft_putstr(YELO);
		}
}

void	gest_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width - len;
	padding -= (p->is_sp_pref || p->show_sign || nbr < 0);
	if (!p->pref_0 && (p->min_width - p->precision - len > 0))
		disp_justif(p->min_width - p->precision - len, p, 0);
	gest_sign_pref(p, nbr);
	if (!p->left_justif && (p->precision - len > 0))
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

void	disp_per_d(t_param *p, int len, int nbr)
{
	if (p->precision >= 0)
		gest_precision(p, nbr, len);
	else
		gest_no_precision(p, nbr, len);
}

int	per_d(va_list va, t_param *p)
{
	long			nbr;
	int				i;

	i = 0;
	p->n_print = 0;
	
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	nbr = va_arg(va, int);
	disp_per_d(p, ft_ilen(nbr), nbr);
	return (p->n_print);
}