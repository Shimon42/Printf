/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:15:38 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 16:33:47 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

typedef struct		s_param
{
	char			*key;
	int				(*treat)(void *, void *);
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
	int				upper;
	struct s_param	*next;
	struct s_brain	*parent;
}					t_param;

typedef	struct		s_brain
{
	t_param			*params;
	t_param			*cur_param;
	int				n_print;
	long			stri;
}					t_brain;

void				disp_brain(t_brain *b);
void				disp_param(t_param *p);

#endif
