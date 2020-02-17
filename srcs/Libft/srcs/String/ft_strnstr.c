/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siferrar <siferrar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:06:22 by siferrar          #+#    #+#             */
/*   Updated: 2020/02/17 17:06:24 by siferrar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle && needle[0] != '\0')
	{
		if (haystack && haystack[i] != '\0')
			while (haystack[i] != '\0' && i < len)
			{
				j = 0;
				while (haystack[i + j] == needle[j] && i + j < len)
				{
					if (needle[j + 1] == '\0' || j >= len)
						return ((char*)&haystack[i]);
					else if (haystack[i + j] != needle[j] || j >= len)
						break ;
					j++;
				}
				i++;
			}
		return ((char*)NULL);
	}
	return ((char*)haystack);
}
