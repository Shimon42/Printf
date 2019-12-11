/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 16:09:46 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	disp_justif(int n, t_param *p, int left_justif)
{
	ft_putstr(CYAN);
	//disp_param(p);
	if (p->left_justif == left_justif && n > 0)
	{
		p->n_print += n;
		while (n-- > 0)
			ft_putchar(p->prefix);
	}
	ft_putstr(YELO);
}

void	gest_wildcard(va_list va, t_param *p)
{
	if (p->min_field_as_var)
		p->min_width = va_arg(va, int);
	if (p->max_field_as_var)
		p->precision = va_arg(va, int);
	if (!p->prefix)
		p->prefix = ' ';
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

void	free_param(t_param *p)
{
	free(p->key);
	free(p);
}