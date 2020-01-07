/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_o.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 17:15:01 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/printf.h"

void	ft_putoctal_fd(unsigned int n, int fd)
{
	if (n <= 7)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putoctal_fd(n / 8, fd);
		ft_putoctal_fd(n % 8, fd);
	}
}

void	per_o(va_list va)
{
	ft_putoctal_fd(va_arg(va, int), 1);
}
