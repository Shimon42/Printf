/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_lu.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:38:53 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft.h"

void		ft_putlong_u_fd(unsigned long n, int fd)
{
	unsigned long long unb;

	unb = n;
	if (unb <= 9)
	{
		ft_putchar_fd(unb + '0', fd);
	}
	else
	{
		ft_putlong_u_fd(unb / 10, fd);
		ft_putlong_u_fd(unb % 10, fd);
	}
}

void	per_lu(va_list va)
{
	ft_putlong_u_fd(va_arg(va, long), 1);
}