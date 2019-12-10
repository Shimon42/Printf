/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puthex.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 20:42:44 by shimon       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 17:20:53 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(uintptr_t n, int upper)
{
	if (n < 16)
	{
		if (upper)
			ft_putchar("0123456789ABCDEF"[n]);
		else
			ft_putchar("0123456789abcdef"[n]);
	}
	else
	{
		ft_puthex(n / 16, upper);
		ft_puthex(n % 16, upper);
	}
}
