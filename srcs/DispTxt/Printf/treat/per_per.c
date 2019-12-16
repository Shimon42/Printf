/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_per.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 23:53:32 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../../includes/printf/printf.h"


static void	gest_precision(t_param *p)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	if (p->min_width > 1)
		padding += p->min_width;
	if (p->precision > 1)
		padding -= p->precision;
	else if (p->precision > 0)
		padding -= 1;
	disp_justif(padding, p, 0);
	if ((!p->left_justif || p->precision) && (p->precision - 1 > 0))
		print_zeros(p, p->precision - 1);
	if (p->precision )
	{
		p->n_print = write(1, "%", 1);
	}
	disp_justif(padding, p, 1);
}

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
	p->n_print = write(1, "%", 1);
	disp_justif(padding, p, 1);
}

int	per_per(va_list va, t_param *p)
{
	va = 0;
//	disp_param(p);
	gest_wildcard(va, p);
	if (p->precision >= 0)
		gest_precision(p);
	else
		gest_no_precision(p);
	return (p->n_print);
}
