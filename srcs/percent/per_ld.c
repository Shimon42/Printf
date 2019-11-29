/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_ld.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:26:22 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void		ft_putlong_fd(long n, int fd)
{
	unsigned long unb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb = n * -1;
	}
	else
		unb = n;
	if (unb <= 9)
	{
		ft_putchar_fd(unb + '0', fd);
	}
	else
	{
		ft_putlong_fd(unb / 10, fd);
		ft_putlong_fd(unb % 10, fd);
	}
}

int				per_ld(va_list va, t_param *p)
{
	unsigned int	n_print;
	long			nbr;
	int				padding;

	n_print = 0;
	nbr = va_arg(va, long);
	padding = ft_llen(nbr) + p->show_sign + ((nbr >= 0) * p->is_sp_pref) + (nbr < 0);
	n_print += disp_justif(p->min_width - padding, p->min_width, 0);
	if (p->is_sp_pref && nbr >= 0)
		n_print += write(1, " ", 1);
	if (p->show_sign)
		(nbr >= 0 ? ft_putchar('+') : ft_putchar('-'));
	ft_putlong_fd(nbr, 1);
	n_print += ft_llen(nbr) + (nbr < 0 || p->show_sign);
	n_print += disp_justif(p->min_width + padding, p->min_width, 1);
	return (n_print);
}