/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gest_params.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:57:07 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 17:39:47 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	disp_justif(int n, t_param *p, int left_justif)
{
	ft_putstr(PINK);
	if (p->left_justif == left_justif && n > 0)
	{
		p->n_print += n;
		while (n-- > 0)
			ft_putchar(p->prefix);
	}
	ft_putstr(YELO);
}

void	free_param(t_param *p)
{
	free(p->key);
	free(p);
}