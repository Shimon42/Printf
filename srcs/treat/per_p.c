/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_p.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:54:33 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int	per_p(va_list va, t_param *p)
{
	int		i;
	int		padding;
	int		nbr;

	i = 0;
	gest_wildcard(va, p);
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	nbr = va_arg(va, int);
	padding = p->is_sp_pref;
	if (!p->pref_0)
		disp_justif(p->min_width - padding, p, 0);
	p->n_print += write(1, "0x", 2);
	if ((p->pref_0 && !p->left_justif))
		while ((i < p->min_width - padding))
		{
			p->n_print += write(1, "0", 1);
			i++;
		}
	ft_puthex((uintptr_t)nbr, 0);
	p->n_print += ft_hexlen(nbr) + (nbr < 0 || p->show_sign);
	disp_justif(p->min_width - padding, p, 1);
	return (p->n_print);
}