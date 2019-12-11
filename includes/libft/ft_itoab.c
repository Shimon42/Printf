/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 15:31:39 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:42:07 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoab(long value, int base)
{
	char *nbr;
  	char fullbase[17] = "0123456789ABCDEF";
	int i;
	char temp;
	int sign;

	nbr = malloc(255 * sizeof(char));
	if (nbr == NULL || base < 2 || base > 16)
		return (NULL);
	sign = 1;
	if (value < 0 && base == 10)
		sign = -1;
	if (value < 0)
		value = -value;
	i = 0;
	if (value == 0)
		return ("0");
	while (value > 0)
	{
		nbr[i] = fullbase[value % base];
		value = (value - (value % base)) / base;
		i++;
	}
	if (sign == -1 && base == 10)
		nbr[i++] = '-';
	while (value < i / 2)
	{
		temp = nbr[value];
		nbr[value] = nbr[i - value - 1];
		nbr[i - value - 1] = temp;
		value++;
	}
	nbr[i] = '\0';
	return (nbr);
}