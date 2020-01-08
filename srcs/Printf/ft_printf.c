/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 15:11:47 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 20:28:41 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/printf.h"

void				init_brain(t_brain **b)
{
	(*b)->cur_param = NULL;
	(*b)->params = NULL;
	(*b)->n_print = 0;
	init_params_list(b);
}

void				meditate(t_brain *b)
{
	t_param *tmp;

	while (b->params)
	{
		tmp = b->params;
		free_param(b->params);
		b->params = tmp->next;
	}
	free(b);
}

static t_param		*analyse(t_brain *b, const char *str)
{
	t_param *ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = new_param(b);
	if (str[i] && (ft_strchr("-+0123456789#.* ", str[i]) != NULL))
	{
		i = get_flags(ret, str, i);
		i = get_min_width(ret, str, i);
		i = get_precision(ret, str, i);
	}
	ret->flags_length = i + 1;
	set_treat_func(b, ret, str + i);
	return (ret);
}

static int			treat_str(t_brain *b, const char *str, va_list va)
{
	int		i;

	i = 0;
	b->n_print = 0;
	while (str[i])
	{
		if ((b->stri = ft_findchar("%", str)) != -1)
		{
			b->n_print += write(1, str, b->stri);
			b->cur_param = analyse(b, str + b->stri + 1);
			if (b->cur_param->key && b->cur_param->treat)
				b->n_print += b->cur_param->treat(va, b->cur_param);
			else
				printf(RED"END BAD KEY - ARG NOT FOUND IN %s"RST"\n", str);
			str += b->stri + b->cur_param->flags_length + 1;
			free_param(b->cur_param);
			i = 0;
		}
		else
			i++;
	}
	b->n_print += write(1, str, ft_strlen(str));
	return (b->n_print);
}

int					ft_printf(const char *str, ...)
{
	va_list	(va);
	t_brain *b;
	int		n_print;

	n_print = 0;
	b = malloc(sizeof(t_brain));
	init_brain(&b);
	va_start(va, str);
	n_print = treat_str(b, str, va);
	va_end(va);
	meditate(b);
	return (n_print);
}
