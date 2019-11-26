/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 23:43:43 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft/libft.h"

size_t	disp_justif(int n, int sup_zero)
{
	int tmp;

	if ((sup_zero && n > 0) || (!sup_zero && n < 0))
	{
		tmp = ft_abs(n);
		while (tmp-- > 0)
			write(1, " ", 1);
	}
	return (ft_abs(n));
}
