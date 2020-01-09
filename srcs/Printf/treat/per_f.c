/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_f.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 16:02:53 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/printf.h"

long	ft_floor(double n)
{
	double left;

	left = n - (long)n;
	return ((int)n);
}

double ft_get_decimals(double n)
{
	double left;

	left = n - (long)n;
	return (left);
}

long	ft_round(double n)
{
	double left;

	left = n - (long)n;
	if (left < 0.5)
		return ((long)n);
	else
		return ((long)n + 1);
}

size_t ft_putfloat(double n, int dec)
{
	size_t count;
	int i;
	//int temp;

	i = 0;
	printf("\n%f\n", n);
	ft_putnbr((long)n);
	n = ft_get_decimals(n);
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	ft_putchar('.');
	n *= 10;
	while (i < 10 && i < dec)
	{
		ft_putnbr(ft_round(n));
		n = ft_get_decimals(n);
		//printf("\ntemp:%f\n", n);
		n *= 10;
		//printf("\nn:%f\n", n);
		i++;
	}
	
	
	return (count);
}

int	per_f(va_list va, t_param *p)
{
	int				padding;

	padding = 0;
	ft_putfloat(va_arg(va, double), 5);
	return (p->n_print);
}
