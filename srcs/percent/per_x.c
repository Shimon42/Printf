/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 21:27:04 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../../includes/libftprintf.h"

void		ft_puthex_fd(unsigned int n, int fd, int upper)
{
	if (n < 16)
	{
		if (upper)
			ft_putchar_fd("0123456789ABCDEF"[n], fd);
		else
			ft_putchar_fd("0123456789abcdef"[n], fd);
	}
	else
	{
		ft_puthex_fd(n / 16, fd, upper);
		ft_puthex_fd(n % 16, fd, upper);
	}
}

static int hex_len(unsigned int n)
{
	int length;

	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int		per_x(va_list va, t_param *p)
{
	unsigned int	n_print;
	int nbr;
	int padding;

	n_print = 0;
	nbr = va_arg(va, int);
	padding = hex_len(nbr) + p->show_sign + (p->hashtag * 2);
	n_print += disp_justif(p->min_width - padding, p, 0);
	if (p->hashtag && nbr != 0)
		n_print += write(1, "0x", 2);
	ft_puthex_fd(nbr, 1, (p->key[0] == 'X'));
	n_print += hex_len(nbr) + (nbr < 0 || p->show_sign);
	n_print += disp_justif(p->min_width + padding, p, 1);
	return (n_print);
}