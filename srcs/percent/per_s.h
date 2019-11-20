/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_s.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:47:19 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 22:53:10 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PER_S_H
# define PER_S_H

typedef struct  s_per_s
{
    char        *key;
    void		(*func)(char *);
	void		*expect;
    void	    *next;
}               t_per_s;

#endif