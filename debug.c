/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 17:07:52 by siferrar    ###    #+. /#+    ###.fr     */
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
    if (p->justif)
		printf(", justif: %d", p->justif);
	else
		printf(", justif: 0");
    if (p->is_sp_pref)
		printf(", sp_pref: %d", p->is_sp_pref);
	else
		printf(", sp_pref: 0");
	if (p->is_0x_pref)
		printf(", 0x: %d", p->is_0x_pref);
	else
		printf(", 0x: 0");
    if (p->show_sign)
		printf(", show_sign: %d", p->show_sign);
	else
		printf(", show_sign: 0");
	if (p->show_dot)
		printf(", dot: %d", p->show_dot);
	else
		printf(", dot: 0");
    if (p->show_dottz)
		printf(", dotz: %d", p->show_dottz);
	else
		printf(", dotz: 0");
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
