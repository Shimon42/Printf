/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_o.c                                          .::    .:/ .      .::   */
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

void		ft_putoctal_fd(unsigned int n, int fd)
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