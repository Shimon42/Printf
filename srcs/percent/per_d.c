/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 19:40:18 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft/libft.h"
#include "../../includes/libftprintf.h"

void	per_d(va_list va, t_param *p)
{
	unsigned long tmp;

	tmp = va_arg(va, unsigned long);
	if (p->justif > 0)
		disp_justif(p->justif - ft_ilen(tmp));
	ft_putnbr_fd(tmp, 1);
	if (p->justif < 0)
		disp_justif(p->justif - ft_ilen(tmp) - 1);
}