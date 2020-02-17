/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:22:17 by shimon            #+#    #+#             */
/*   Updated: 2020/02/17 17:06:29 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	iter;

	if (s)
	{
		iter = 0;
		while (s[iter] != '\0')
			iter++;
		if (c == '\0')
			return ((char*)&s[iter]);
		while (iter >= 0)
			if (s[iter--] == c)
				return ((char*)&s[iter + 1]);
	}
	return (NULL);
}
