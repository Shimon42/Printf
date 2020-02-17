/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:24:29 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:03:34 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlst;

	if ((newlst = malloc(sizeof(t_list))) != NULL)
	{
		newlst->content = content;
		newlst->next = NULL;
	}
	return (newlst);
}
