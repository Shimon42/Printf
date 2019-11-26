/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:15:38 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 18:53:25 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#ifndef BRAIN_H
# define BRAIN_H

typedef void (*funcptr)(void *, void *);

typedef struct  	s_param
{
    char			*key;
    funcptr			treat;
	int				justif;
	int				show_sign;
	int				is_sp_pref;
	int				is_0x_pref;
	int				show_dot;
	int				show_dottz;
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