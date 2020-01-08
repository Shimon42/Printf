/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   per_f.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:01:41 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 19:48:48 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/printf.h"



size_t ft_putfloat(double n, int dec)
{
	size_t count;
	int i;
	double temp;

	i = 0;
	printf("\n%f\n", n);

	ft_ftoa(n, 5);

	ft_putnbr((long)n);
	n = n - (long)n;
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
		ft_putnbr(n);
		temp = n - (int)n;
		printf("\ntemp:%f\n", temp);
		n = (temp * 10);
		printf("n:%f\n", n);
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
