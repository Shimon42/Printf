/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 16:31:38 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft/libft.h"

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

void	per_x(va_list va)
{
	ft_puthex_fd(va_arg(va, int), 1);
}