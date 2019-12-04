/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_c.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 18:01:16 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/libftprintf.h"

int	per_c(va_list va, t_param *p)
{
	unsigned int	n_print;
	int				i;
	int				padding;

	i = 0;
	n_print = 1;
	padding = 1 + p->is_sp_pref;
	if (!p->pref_0)
		n_print += disp_justif(p->min_width - padding, p->left_justif, 0);
	if ((p->pref_0 && !p->left_justif))
		while ((i < p->min_width - padding))
		{
			n_print += write(1, "0", 1);
			i++;
		}
	ft_putchar(va_arg(va, int));
	n_print += disp_justif(p->min_width - padding, p->left_justif, 1);
	return (n_print);
}