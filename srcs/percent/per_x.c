/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 16:42:08 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../../includes/libftprintf.h"

int		per_x(va_list va, t_param *p)
{
	unsigned int	n_print;
	int nbr;
	int padding;

	n_print = 0;
	nbr = va_arg(va, int);
	padding = hex_len(nbr) + p->show_sign + (p->hashtag * 2);
	disp_justif(p->min_width - padding, p, 0);
	if (p->hashtag && nbr != 0)
		n_print += write(1, "0x", 2);
	ft_puthex(nbr, (p->key[0] == 'X'));
	n_print += ft_hexlen(nbr) + (nbr < 0 || p->show_sign);
	disp_justif(p->min_width + padding, p, 1);
	return (n_print);
}