/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 21:12:34 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	disp_justif(int n, int justif, int left_justif)
{
	int tmp;

	tmp = n;
	if (justif == left_justif && n > 0)
	{
		while (n-- > 0)
			write(1, " ", 1);
		return (tmp);
	}
	return (0);
}

void	free_param(t_param *p)
{
	free(p->key);
	free(p);
}