/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 15:11:47 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 21:20:11 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/printf.h"

static int		check_key(const char *str, char *tofind)
{
	size_t	x;
	size_t	i;
	char	upper;
	size_t	to_f_len;

	to_f_len = ft_strlen(tofind);
	x = 0;
	i = 0;
	if (tofind[0] != '\0')
	{
		upper = ft_toupper(str[x]);
		while (str[x] && upper == ft_toupper(tofind[x]) && x < to_f_len)
		{
			if (tofind[x + 1] == '\0')
				return (0);
			else if (upper != ft_toupper(tofind[x]))
				break ;
			x++;
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
				if (needles[j++] == str[i])
					return (i);
			i++;
		}
	}
	return (-1);
}

static t_param	*new_param(void)
{
	t_param *new;

	if (!(new = malloc(sizeof(t_param))))
		return (NULL);
	new->key = NULL;
	new->treat = NULL;
	new->min_width = 0;
	new->show_sign = 0;
	new->is_sp_pref = 0;
	new->hashtag = 0;
	new->precision = -1;
	new->left_justif = 0;
	new->pref_0 = 0;
	new->max_width = -1;
	new->min_field_as_var = 0;
	new->max_field_as_var = 0;
	new->next = NULL;
	return (new);
}

static void		add_param(t_brain **b, char *key, void *f)
{
	t_param *new;

	new = new_param();
	new->key = ft_strdup(key);
	new->treat = f;
	new->next = (*b)->params;
	(*b)->params = new;
}

static void		init_params_list(t_brain **b)
{
	add_param(b, "c", &per_c);
	add_param(b, "s", &per_s);
	add_param(b, "d", &per_d);
	add_param(b, "p", &per_p);
	add_param(b, "u", &per_u);
	add_param(b, "i", &per_d);
	add_param(b, "x", &per_x);
	add_param(b, "u", &per_u);
	add_param(b, "%", &per_per);
}

void			init_brain(t_brain **b)
{
	(*b)->cur_param = NULL;
	(*b)->params = NULL;
	init_params_list(b);
}

void			meditate(t_brain *b)
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
		if ((found = check_key(str, (*tmp)->key)) > -1)
		{
			ret = tmp;
			if (ft_strchr("XEG", str[found]))
				(*ret)->key[0] = str[found];
			break ;
		}
		tmp = &((*tmp)->next);
	}
	if (ret == NULL)
		return (NULL);
	return (*ret);
}

static funcptr		set_treat_func(t_brain *b, t_param *cur, const char *str)
{
	t_param *res;

	res = find_func(b, str);
	if (res)
	{
		cur->treat = res->treat;
		cur->key = ft_strdup(res->key);
		return (res->treat);
	} else
		printf (RED"NO FUNC FOUND FOR %s"RST"\n", str);
	return (NULL);
}

static int			get_flags(t_param *ret, const char *str, int i)
{
	while (ft_strchr("-+0 #", str[i]))
	{
		if (str[i] == '-')
		{
			ret->left_justif = 1;
			ret->prefix = ' ';
		}
		else if (str[i] == '+')
			ret->show_sign = 1;
		else if (str[i] == ' ')
			ret->is_sp_pref = 1;
		else if (str[i] == '0' && !ret->left_justif)
		{
			ret->prefix = '0';
			ret->pref_0 = 1;
		}
		else if (str[i] == '#')
			ret->hashtag = 1;
		i++;
	}
	return (i);
}

static int			get_min_width(t_param *ret, const char *str, int i)
{
	if (str[i] == '*')
	{
		ret->min_field_as_var = 1;
		i++;
	}
	else if (str[i] >= '1' && str[i] <= '9' && !ret->min_field_as_var)
	{
		ret->min_width = ft_atoi(str + i);
		if (!ret->prefix)
			ret->prefix = ' ';
		i += ft_ilen(ret->min_width);
	}
	return (i);
}

static int			get_precision(t_param *ret, const char *str, int i)
{
	if (str[i] == '.')
	{
		i++;
		ret->prefix = ' ';
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] == '0')
				i++;
			ret->precision = ft_atoi(str + i);
			if (ret->precision)
				i += ft_ilen(ret->precision);
		}
		else if (str[i] == '*')
		{
			ret->max_field_as_var = 1;
			i++;
		}
		else
			ret->precision = 0;
	}
	return (i);
}

static t_param		*analyse(t_brain *b, const char *str)
{
	t_param *ret;
	int i;
	int j;

	i = 0;
	j = 0;
	ret = new_param();
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
	int		n_print;

	i = 0;
	n_print = 0;
	while (str[i])
	{
		if ((b->stri = ft_findchar("%", str)) != -1)
		{
			n_print += write(1, str, b->stri);
			b->cur_param = analyse(b, str + b->stri + 1);
			if (b->cur_param->key && b->cur_param->treat)
				n_print += b->cur_param->treat(va, b->cur_param);
			else
				printf(RED"END BAD KEY - ARG NOT FOUND IN %s"RST"\n", str);
			str += b->stri + b->cur_param->flags_length + 1;
			free_param(b->cur_param);
			i = 0;
		}
		else
			i++;
	}
	n_print += write(1, str, ft_strlen(str));
	return (n_print);
}

int			ft_printf(const char *str, ...)
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
