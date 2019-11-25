/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_u.c                                          .::    .:/ .      .::   */
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

void		ft_putnbr_u_fd(unsigned long n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
	}
}

void	per_u(va_list va)
{
	ft_putnbr_u_fd(va_arg(va, unsigned int), 1);
}