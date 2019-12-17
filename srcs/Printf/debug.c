/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:53:12 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 21:46:24 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/debug.h"
#include "../../includes/brain.h"


void disp_param(t_param *p)
{
	if (p->key)
       	printf(CYAN"\n{\n"TAB GRN"key"RST": %s,\n", p->key);
	else
		printf(CYAN"\n{\n"TAB RED"!key"RST": null,\n");

	if (p->treat)
       	printf(TAB GRN"treat"RST": set,\n");
	else
		printf(TAB RED"!treat"RST": null,\n");

    if (p->left_justif)
		printf(TAB GRN"left_justif"RST": %d,\n", p->left_justif);
	else
		printf(TAB YELO"left_justif"RST": 0,\n");
	
	if (p->min_field_as_var)
		printf(TAB GRN"min_as_var"RST": %d,\n", p->min_field_as_var);
	else
		printf(TAB YELO"min_as_var"RST": 0,\n");

	if (p->min_width)
		printf(TAB GRN"min_width"RST": %d,\n", p->min_width);
	else
		printf(TAB YELO"min_width"RST": 0,\n");

    if (p->prefix)
		printf(TAB GRN"prefix"RST": '%c',\n", p->prefix);
	else
		printf(TAB YELO"prefix"RST": null,\n");
	
	if (p->is_sp_pref)
		printf(TAB GRN"sp_pref"RST": %d,\n", p->is_sp_pref);
	else
		printf(TAB YELO"sp_pref"RST": 0,\n");
	
	if (p->pref_0)
		printf(TAB GRN"pref_0"RST": %d,\n", p->pref_0);
	else
		printf(TAB YELO"pref_0"RST": 0,\n");

	if (p->hashtag)
		printf(TAB GRN"#"RST": %d,\n", p->hashtag);
	else
		printf(TAB YELO"#"RST": 0,\n");

	if (p->max_field_as_var)
		printf(TAB GRN"max_as_var"RST": %d,\n", p->max_field_as_var);
	else
		printf(TAB YELO"max_as_var"RST": 0,\n");
	
	if (p->precision >= 0)
		printf(TAB GRN"precision"RST": %d,\n", p->precision);
	else
		printf(TAB YELO"precision"RST": -1,\n");

	if (p->max_width)
		printf(TAB GRN"max_width"RST": %d,\n", p->max_width);
	else
		printf(TAB YELO"max_width"RST": 0,\n");

    if (p->show_sign)
		printf(TAB GRN"show_sign"RST": %d,\n", p->show_sign);
	else
		printf(TAB YELO"show_sign"RST": 0,\n");
    
	if (p->flags_length)
		printf(TAB GRN"flags_length"RST": %d,\n", p->flags_length);
	else
		printf(TAB YELO"flags_length"RST": 0,\n");
		
	if (p->next)
       	printf(TAB GRN"next"RST": %s\n"CYAN"}"RST"\n", (char *)(p->next)->key);
	else
		printf(TAB CYAN"!next"RST": null\n"CYAN"}"RST"\n");
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
