/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 17:10:31 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/brain.h"
#include <stdio.h>
#include "includes/debug.h"

void disp_brain (t_brain *b)
{
    t_param **params;

    params = &(b->params);
    printf(CYAN"┌────────────────────────────\n");
    printf("|----------- BRAIN ----------\n");
    printf("|\n");
    printf("|\tParams:\n");
    while (*params != NULL)
    {
		if ((*params)->key)
       		printf("|\t\t%s\n", (*params)->key);
        params = &((*params)->next);
    }
    printf("────────────────────────────"RST"\n");
}