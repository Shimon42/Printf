/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 17:52:28 by siferrar    ###    #+. /#+    ###.fr     */
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
	int	padding;
	int i;

	i = 0;
	padding = 0;
	if (p->precision < len)
		len = p->precision;
	if (p->min_width > len)
		padding += p->min_width - len;
	padding -= (p->is_sp_pref || p->show_sign);
	if (p->prefix != '0' && p->min_width > len)
		disp_justif(padding, p, 0);
	gest_sign_pref(p, nbr);
	if ((p->min_width > len && (!p->left_justif)) || (p->precision > len))
		while (i < p->min_width - len - p->precision - (p->show_sign || p->is_sp_pref))
		{
			ft_putstr(RED);
			p->n_print += write(1, "0", 2);
			ft_putstr(YELO);
			i++;
		}
	ft_putnbr_fd(ft_abs(nbr), 1);
	p->n_print += len;
	disp_justif(ft_abs(padding), p, 1);
}

void	gest_no_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width - len;
	padding -= (p->is_sp_pref || p->show_sign);
	if (p->prefix != '0' && p->min_width > len)
		disp_justif(padding, p, 0);
	gest_sign_pref(p, nbr);
	if ((p->min_width > len && (!p->left_justif)) || (p->precision > len))
		while (i < p->min_width - len - (p->show_sign || p->is_sp_pref))
		{
			ft_putstr(RED);
			p->n_print += write(1, "0", 2);
			ft_putstr(YELO);
			i++;
		}
	ft_putnbr_fd(ft_abs(nbr), 1);
	p->n_print += len;
	disp_justif(ft_abs(padding), p, 1);
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