/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 23:12:33 by siferrar    ###    #+. /#+    ###.fr     */
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
	if (p->treat)
       	printf(", treat: set");
	else
		printf(", !treat: null");
    printf(", justif: %d", p->justif);
    printf(", 0x: %d", p->is_0x_pref);
    printf(", dot: %d", p->show_dot);
    printf(", dotz: %d", p->show_dottz);
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
