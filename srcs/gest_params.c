/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 15:25:22 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	disp_justif(int n, int justif, int left_justif)
{
	int tmp;

	if ((justif > 0 && !left_justif) || (justif < 0 && left_justif))
	{
		tmp = ft_abs(n);
		while (tmp-- > 0)
			write(1, " ", 1);
		return (ft_abs(n));
	}
	return (0);
}

void	free_param(t_param *p)
{
	free(p->key);
	free(p);
}