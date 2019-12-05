/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_s.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 23:23:25 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int	per_s(va_list va, t_param *p)
{
	char	*str;
	int		i;
	int		padding;
	int		len;

	i = 0;
	str = va_arg(va, char *);
	len = ft_strlen(str);
	
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	p->n_print = 0;
	if (p->precision >= 0)
	{
		padding = (p->min_width > len) * (p->min_width) - ((p->precision < len) * (p->precision));
		printf("\npadding: %d\n", padding);
		disp_justif(ft_abs(padding), p, 0);
		p->n_print += ft_putnstr(str, p->precision);
		disp_justif(ft_abs(p->precision - p->min_width), p, 1);
	}
	else
	{
		padding = (p->min_width > len) * (p->min_width - len);
		disp_justif(padding, p, 0);
		p->n_print += ft_putnstr(str, len);
		disp_justif(padding, p, 1);
	}
	return (p->n_print);
}