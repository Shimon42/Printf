/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 21:45:25 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/brain.h"
#include <stdio.h>
#include "includes/debug.h"

void disp_param(t_param *p)
{
	if (p->key)
       	printf("|\t\t{ "GRN"key"RST": %s,\t", p->key);
	else
		printf("|\t\t{ "RED"!key"RST": null,\t");

	if (p->treat)
       	printf(GRN"treat"RST": set, ");
	else
		printf(RED"!treat"RST": null, ");

    if (p->left_justif)
		printf(GRN"left_justif"RST": %d, ", p->left_justif);
	else
		printf(YELO"left_justif"RST": 0, ");

	if (p->min_width)
		printf(GRN"min_width"RST": %d, ", p->min_width);
	else
		printf(YELO"min_width"RST": 0, ");

    if (p->prefix)
		printf(GRN"prefix"RST": '%c', ", p->prefix);
	else
		printf(YELO"prefix"RST": null, ");
	
	if (p->is_sp_pref)
		printf(GRN"sp_pref"RST": %d, ", p->is_sp_pref);
	else
		printf(YELO"sp_pref"RST": 0, ");
	
	if (p->pref_0)
		printf(GRN"pref_0"RST": %d, ", p->is_sp_pref);
	else
		printf(YELO"pref_0"RST": 0, ");

	if (p->hashtag)
		printf(GRN"#"RST": %d, ", p->hashtag);
	else
		printf(YELO"#"RST": 0, ");

	if (p->precision)
		printf(GRN"precision"RST": %d, ", p->precision);
	else
		printf(YELO"precision"RST": 0, ");

	if (p->max_width)
		printf(GRN"max_width"RST": %d, ", p->max_width);
	else
		printf(YELO"max_width"RST": 0, ");

    if (p->show_sign)
		printf(GRN"show_sign"RST": %d, ", p->show_sign);
	else
		printf(YELO"show_sign"RST": 0, ");
		
	if (p->next)
       	printf(GRN"next"RST": %s }\n", (char *)(p->next)->key);
	else
		printf(CYAN"!next"RST": null }\n");
}

void disp_brain(t_brain *b)
{
    t_param **params;

    params = &(b->params);
    printf(CYAN"┌────────────────────────────\n");
    printf("|----------- BRAIN ----------\n");
    printf("|\n");
    printf(YELO"|\tParams:\n");
    while (*params != NULL)
    {
		disp_param(*params);
        params = &((*params)->next);
    }
    printf("────────────────────────────"RST"\n");
}
