/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 15:11:47 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 19:41:17 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "includes/brain.h"
#include <stdlib.h>
#include "includes/libft/libft.h"
#include "includes/debug.h"
#include "includes/libftprintf.h"

static void		init_params_list(t_brain **b);

int		ft_strstr(const char *str, char *tofind)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (tofind[0] != '\0')
	{
		if (str[i] != '\0')
			while (str[i] != '\0')
			{
				x = 0;
				while (str[i + x] == tofind[x])
				{
					if (tofind[x + 1] == '\0')
						return (i);
					else if (str[i + x] != tofind[x])
						break ;
					x++;
				}
				i++;
			}
	}
	return (-1);
}

static	int		ft_findchar(const char *needles, const char *str)
{
	size_t i;
	size_t j;

	if (str && needles)
	{
		i = 0;
		while (str[i])
		{
			j = 0;
			while (needles[j] != '\0')
			{
				if (needles[j] == str[i])
					return (i);
				j++;
			}
			i++;
		}
	}
	return (-1);
}

void			init_brain(t_brain **b)
{
	(*b)->cur_param = NULL;
	(*b)->params = malloc(2 * sizeof(t_param));
	(*b)->params = NULL;
	init_params_list(b);
}

void			meditate(t_brain *b)
{
	free(b);
//	ft_clear_params(&(b->params), &free);
}

static t_param	*new_param(void)
{
	t_param *new;

	if (!(new = malloc(sizeof(t_param))))
		return (NULL);
	new->key = NULL;
	new->treat = NULL;
	new->next = NULL;
	new->justif = 0;
	new->show_sign = 0;
	new->is_sp_pref = 0;
	new->is_0x_pref = 0;
	new->show_dot = 0;
	new->show_dottz = 0;
	return (new);
}

void			add_param(t_brain **b, char *key, void *f)
{
	t_param *new;

	new = new_param();
	new->key = ft_strdup(key);
	new->treat = f;
	new->next = (*b)->params;
	new->justif = 1;
	new->show_sign = 0;
	new->is_0x_pref = 0;
	new->show_dot = 0;
	new->show_dottz = 0;
	(*b)->params = new;
}

static void			init_params_list(t_brain **b)
{
	//printf(YELO"Init params"RST"\n");
	add_param(b, "c", &per_c);
	add_param(b, "s", &per_s);
	add_param(b, "d", &per_d);
	add_param(b, "lu", &per_lu);
	add_param(b, "ld", &per_ld);
	add_param(b, "u", &per_u);
	add_param(b, "o", &per_o);
	add_param(b, "x", &per_x);
	disp_brain(*b);
	//printf(GRN"END Init params"RST"\n");
}

static t_param	*find_func(t_brain *b, const char *str)
{
	t_param **tmp;
	t_param **ret;
	int		first_found;
	int		found;

	tmp = &(b->params);
	ret = NULL;
	first_found = ft_strlen(str);
	while (*tmp != NULL)
	{
		//printf("\nSearching for %s in '%s'\n", (*tmp)->key, str);
		if ((found = ft_strstr(str, (*tmp)->key)) > -1)
		{
			//printf("FOUND\n");
			if (found < first_found)
			{
				//printf("first of type in str\n");
				first_found = found;
				ret = tmp;
				//printf(YELO"Key: %s"RST"\n", (*ret)->key);
			}
		}
		//printf("end for %s\n", (*tmp)->key);
		tmp = &((*tmp)->next);
		//printf("ok\n");
	}
	//printf("FIND FUNC OUT\n");
	if (ret == NULL)
		return (NULL);
	return (*ret);
}

static funcptr		set_treat_func(t_brain *b, t_param *cur, const char *str)
{
	t_param *res;

	//printf("str find func: %s\n", str);
	res = find_func(b, str);
	if (res)
	{
		//printf("FOUND FUNC %s\n", res->key);
		cur->treat = res->treat;
		cur->key = ft_strdup(res->key);
		return (res->treat);
	}
	return (NULL);
}

static t_param		*get_flags(t_brain *b, const char *str)
{
	t_param *ret;
	int i;
	int j;

	i = 0;
	j = 0;
	ret = new_param();
//	printf(GRN"GET FLAGS\n"RST);
	while ((ft_strchr("-+0123456789#% ", str[i]) != NULL) && str[i])
	{
		//printf("Curchar: %c\n", str[i]);
		if (str[i] == '+')
			ret->show_sign = 1;
		else if (ret->justif == 0
		&& (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		{
			if (str[i] == '-')
				ret->justif = -1;
			while (!(str[i + j] >= '0' && str[i + j] <= '9') && str[i + j])
				j++;
			ret->justif =
			(ret->justif == 0 ? 1 : ret->justif) * ft_atoi(str + i + j);
		}
		else if (str[i] == ' ')
			ret->is_sp_pref = 1;
		else if (str[i] == '#')
			ret->is_0x_pref = 1;
		i++;
	}
	//printf("END While - get flags\n");
	set_treat_func(b, ret, str + i);
	//disp_param(ret);
	return (ret);
}

static int			calc_skip(t_param *p)
{
	int length;

	//disp_param(p);
	length = 0;
	length += ft_strlen(p->key);
	if (p->justif > 0)
		length += ft_ilen(p->justif);
	if (p->justif < 0)
		length += ft_ilen(p->justif) + 1;
	length += p->show_sign;
	length += p->is_sp_pref;
	length += p->is_0x_pref;
	length += p->show_dot;
	length += p->show_dottz;
	//printf("skip length: %d\n", length);
	return (length);
}

static int			treat_str(t_brain *b, const char *str, va_list va)
{
	int		i;
	void	*cur_va;

	cur_va = va;
	i = 0;
	while (str[i])
	{
		if ((b->stri = ft_findchar("%", str)) != -1)
		{
			write(1, str, b->stri);
			b->cur_param = get_flags(b, str + b->stri + 1);
			//disp_param(b->cur_param);
			b->cur_param->treat(va, b->cur_param);
			i += b->stri + 1;
			str += b->stri + calc_skip(b->cur_param) + 1;
		}
		else
			i++;
	}
	write(1, str, ft_strlen(str));
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	(va);
	t_brain *b;

	printf(CYAN"TRY TO PRINT: "YELO"%s"PINK"[END]\n"RST, str);
	b = malloc(sizeof(t_brain));
	init_brain(&b);
	va_start(va, str);
	treat_str(b, str, va);
	va_end(va);
	meditate(b);
	return (1);
}
