/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 23:11:15 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft/libft.h"
#include "../../includes/libftprintf.h"

void		ft_puthex_fd(unsigned int n, int fd)
{
	if (n < 16)
	{
		ft_putchar_fd("0123456789abcdef"[n], fd);
	}
	else
	{
		ft_puthex_fd(n / 16, fd);
		ft_puthex_fd(n % 16, fd);
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

void	per_x(va_list va, t_param *p)
{
	int tmp;

	tmp = va_arg(va, int);
	disp_justif(p->justif - hex_len(tmp), 1);
	ft_puthex_fd(tmp, 1);
	disp_justif(p->justif + hex_len(tmp), 0);
}