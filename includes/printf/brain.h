/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:15:38 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 20:56:06 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#ifndef BRAIN_H
# define BRAIN_H

typedef int (*funcptr)(void *, void *);

typedef struct  	s_param
{
    char			*key;
    funcptr			treat;
	int				left_justif;
	int				min_field_as_var;
	int				max_field_as_var;
	int				min_width;
	int				max_width;
	int				show_sign;
	int				is_sp_pref;
	char			prefix;
	int				pref_0;
	int				hashtag;
	int				precision;
	int				flags_length;
	int				n_print;
    struct s_param	*next;
}					t_param;

typedef struct  s_brain
{
    t_param		*params;
	t_param		*cur_param;
    long		stri;
}               t_brain;

void disp_brain(t_brain *b);
void disp_param(t_param *p);

#endif