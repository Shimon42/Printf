/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:48:59 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 17:41:02 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list **tmp;

	tmp = NULL;
	if (*lst)
	{
		tmp = lst;
		while (*tmp)
		{
			*tmp = (*tmp)->next;
			ft_lstdelone(*tmp, del);
			*tmp = (*tmp)->next;
		}
		*tmp = NULL;
	}
	*lst = NULL;
}
