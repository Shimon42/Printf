/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:37:05 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 17:57:09 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (size - i == 0)
		return (i + ft_strlen(src));
	else
		while (src[j] != '\0' && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}
