/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 21:06:39 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	disp_justif(int n, t_param *p, int left_justif)
{
	if (p->left_justif == left_justif && n > 0)
	{
		p->n_print += n;
		while (n-- > 0)
			ft_putchar(p->prefix);
	}
}

void	free_param(t_param *p)
{
	free(p->key);
	free(p);
}