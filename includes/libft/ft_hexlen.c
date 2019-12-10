/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hexlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 13:08:54 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 17:19:49 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

uintptr_t		ft_hexlen(unsigned int n)
{
	uintptr_t length;

	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}
