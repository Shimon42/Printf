/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_per.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 21:50:14 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/printf.h"

static void	gest_no_precision(t_param *p)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > 1)
		padding += p->min_width - 1;
	if (!p->pref_0)
		disp_justif(padding, p, 0);
	if (!p->left_justif && p->pref_0)
		print_zeros(p, padding);
	p->n_print += write(1, "%", 1);
	disp_justif(padding, p, 1);
}

int	per_per(va_list va, t_param *p)
{
	va = 0;
//	disp_param(p);
	p->n_print = 0;
	gest_wildcard(va, p);
	gest_no_precision(p);
	return (p->n_print);
}
