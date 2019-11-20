/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 23:02:33 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/brain.h"
#include <stdio.h>
#include "includes/debug.h"

void disp_param(t_param *p)
{
	if (p->key)
       	printf("|\t\t{ key: %s", p->key);
	else
		printf("|\t\t{ !key: null");
	if (p->expect)
       	printf(", expect: set");
	else
		printf(", !expect: null");
	if (p->next)
       	printf(", next: %s }\n", (char *)(p->next)->key);
	else
		printf(", !next: null }\n");
}

void disp_brain(t_brain *b)
{
    t_param **params;

    params = &(b->params);
    printf(CYAN"┌────────────────────────────\n");
    printf("|----------- BRAIN ----------\n");
    printf("|\n");
    printf("|\tParams:\n");
    while (*params != NULL)
    {
		disp_param(*params);
        params = &((*params)->next);
    }
    printf("────────────────────────────"RST"\n");
}