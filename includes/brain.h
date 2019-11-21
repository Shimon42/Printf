/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:15:38 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:04:06 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#ifndef BRAIN_H
# define BRAIN_H

typedef void (*funcptr)(void *);

typedef struct  s_param
{
    char		*key;
    funcptr		treat;
    struct s_param	*next;
}               t_param;

typedef struct  s_brain
{
    t_param		*params;
	t_param		*cur_func;
    long		stri;
}               t_brain;

void disp_brain(t_brain *b);

#endif