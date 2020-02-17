/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:02:24 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:02:26 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
