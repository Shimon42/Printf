/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_s.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 23:27:20 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/brain.h"
#include "../../includes/libft.h"

void	new_s_param(t_brain **b, char *key, void (*f)(char *), void *exp)
{
	t_param *new;

	new = malloc(sizeof(t_param));
	new->key = ft_strdup(key);
	new->func = f;
	new->next = (*b)->params;
	new->expect = &exp;
	(*b)->params = new;
}

char	*per_s_exp(va_list va)
{
	return (va_arg(va, char *));
}