/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:15:38 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 18:04:54 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#ifndef BRAIN_H
# define BRAIN_H

typedef struct  s_param
{
    char        *key;
    void        *func;
    struct s_param     *next;
}               t_param;

typedef struct  s_brain
{
    t_param		*params;
	t_param		*cur_param;
    long		stri;
}               t_brain;

void disp_brain(t_brain *b);

#endif