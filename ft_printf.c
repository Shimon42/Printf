/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 15:11:47 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:36:17 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "includes/brain.h"
#include <stdlib.h>
#include "includes/libft.h"
#include "includes/debug.h"
#include "includes/libftprintf.h"

static void		init_params(t_brain **b);

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
	(*b)->cur_func = malloc(sizeof(t_param));
	(*b)->params = malloc(2 * sizeof(t_param));
	(*b)->params = NULL;
	init_params(b);
}

void			new_param(t_brain **b, char *key, void *f)
{
	t_param *new;

	new = malloc(sizeof(t_param));
	new->key = ft_strdup(key);
	new->treat = f;
	new->next = (*b)->params;
	(*b)->params = new;
}

static void			init_params(t_brain **b)
{
	printf(YELO"Init params"RST"\n");
	new_param(b, "%c", &per_c);
	new_param(b, "%s", &per_s);
	new_param(b, "%d", &per_d);
	new_param(b, "%lu", &per_lu);
	new_param(b, "%ld", &per_ld);
	new_param(b, "%u", &per_u);
	disp_brain(*b);
	printf(GRN"END Init params"RST"\n");
}

t_param				*find_func(t_brain *b, const char *str)
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
		//printf("\nSearching for %s\n", (*tmp)->key);
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
	}
	//printf("find function for %s\n", (*ret)->key);
	return (*ret);
}

static int			treat_str(t_brain *b, const char *str, va_list va)
{
	int		i;
	void	*cur_va;

	cur_va = NULL;
	i = 0;
	while (str[i])
	{
		if ((b->stri = ft_findchar("%", str)) != -1)
		{
			//printf("\nFound at %ld\n", b->stri);
			write(1, str, b->stri);
			b->cur_func = find_func(b, str);
			//ft_putstr_fd("OKOKOKOKOKOKOKOKOKOK\n", 1);
			//printf("\ncurFunc Key: %s", b->cur_func->key);
			(b->cur_func->treat)(va);
			//(b->cur_func->func)(cur_va);

			i += b->stri + 1;
			str += b->stri + ft_strlen(b->cur_func->key);
		}
		else
			i++;
	}
	write(1, str, ft_strlen(str));
	//printf("END TREAT\n");
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	(va);
	t_brain *b;

	b = malloc(sizeof(t_brain));
	init_brain(&b);
	va_start(va, str);
	treat_str(b, str, va);
	va_end(va);
	return (1);
}
