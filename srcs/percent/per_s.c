/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_s.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:30:30 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	disp_per_s(t_param *p, int len, char * str)
{
	int padding;
	int i;

	i = 0;
	padding = 0;
	p->n_print = 0;
	if (p->precision >= 0)
		if (p->precision < len)
			len = p->precision;
	if (p->min_width > len)
		padding += p->min_width - len;
	if (!p->pref_0)
		disp_justif(padding, p, 0);
	if ((p->pref_0 && !p->left_justif))
		while ((i < padding))
		{
			ft_putstr(PINK);
			p->n_print += write(1, "0", 1);
			ft_putstr(YELO);
			i++;
		}
	p->n_print += ft_putnstr(str, len);
	disp_justif(ft_abs(padding), p, 1);
}

int		per_s(va_list va, t_param *p)
{
	char	*str;
	int		len;
	disp_param(p);
	gest_wildcard(va, p);
	disp_param(p);
	ft_putstr(YELO"\nd: ");
	str = va_arg(va, char *);
	len = ft_strlen(str);
	disp_per_s(p, len, str);
	return (p->n_print);
}