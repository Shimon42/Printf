/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 16:39:18 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static void	gest_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width;
	if (p->precision > len)
		padding -= p->precision;
	else if (p->precision > 0)
		padding -= len;
	if (p->hashtag && nbr != 0)
		padding -= 2;
	disp_justif(padding, p, 0);
	if (p->hashtag && nbr != 0)
		p->n_print += write(1, "0x", 2);
	if ((!p->left_justif || p->precision) && (p->precision - len > 0))
		print_zeros(p, p->precision - len);
	if (p->precision || nbr != 0)
	{
		ft_puthex(ft_abs(nbr), (p->key[0] == 'X'));
		p->n_print += len;
	}
	disp_justif(padding, p, 1);
}

static void	gest_no_precision(t_param *p, int nbr, int len)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > len)
		padding += p->min_width - len;
	if (p->hashtag && nbr != 0)
		padding -= 2;
	if (!p->pref_0)
		disp_justif(padding, p, 0);
	if (p->hashtag && nbr != 0)
		p->n_print += write(1, "0x", 2);
	if (!p->left_justif && p->pref_0)
		print_zeros(p, padding);
	ft_puthex(nbr, (p->key[0] == 'X'));
	p->n_print += len;
	disp_justif(padding, p, 1);
}

int	per_x(va_list va, t_param *p)
{
	long	nbr;
	int		i;

	i = 0;
	p->n_print = 0;
	gest_wildcard(va, p);
	nbr = va_arg(va, int);
	disp_param(p);
	ft_putstr(YELO"\nx: ");
	if (p->precision >= 0)
		gest_precision(p, nbr, ft_hexlen(nbr));
	else
		gest_no_precision(p, nbr, ft_hexlen(nbr));
	return (p->n_print);
}