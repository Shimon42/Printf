/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_ld.c                                         .::    .:/ .      .::   */
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

void	per_ld(va_list va)
{
	ft_putlong_fd(va_arg(va, long), 1);
}