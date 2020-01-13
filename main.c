/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 17:46:07 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/printf.h"
#include "debug.h"
#include <limits.h>
int main(void)
{
	unsigned long nbr = 12;
	printf("\n RET->%d\n", ft_printf("%.lu",nbr));
	printf("\n RET->%d\n", ft_printf("%.p",NULL));
	printf("\n RET->%d\n", printf("%.p",NULL));
	printf("\n RET->%d\n", ft_printf("%.p",&nbr));
	printf("\n RET->%d\n", printf("%.p",&nbr));
	printf("\n RET->%d\n", ft_printf("[%u %X %x %s %p %s %d %u %x %X %s]", 2987, 2978123, 982374, "ah", NULL, "bon", 28763, 82763, 376482, 387936, "hello"));
	printf("\n RET->%d\n",    printf("[%u %X %x %s %p %s %d %u %x %X %s]", 2987, 2978123, 982374, "ah", NULL, "bon", 28763, 82763, 376482, 387936, "hello"));

/*
	printf(PINK"------------ %%s 42 ------------"RST"\n");
	
	ft_printf(YELO);
	printf("\nMINE RET->%d\n", ft_printf("%.0s", ""));
	ft_printf(GRN);
	printf("\nREAL RET->%d\n", printf("%.0s", 42));
*/
	/*
	printf(PINK"------------ %%n ------------"RST"\n");
	int nbr = 0;
	int nbr2 = 0;
	
	ft_printf(YELO);
	printf("\nMINE RET->%d - NBR: %d\n", ft_printf("hlkjhd dsfmjhf  dsf fdqsdf qsdf sqdf %n qsdfsdf qsdf", &nbr), nbr);
	ft_printf(GRN);
	printf("\nREAL RET->%d - NBR: %d\n", printf("hlkjhd dsfmjhf  dsf fdqsdf qsdf sqdf %n qsdfsdf qsdf", &nbr2), nbr2);
*/
/*
	printf(PINK"------------ %%p ------------"RST"\n");
	ft_printf(YELO);
	int nbr = 6;
	printf("\nMINE RET->%d\n", ft_printf("%p", &nbr));
	printf("\nMINE RET->%d\n", ft_printf("%p", &nbr));
	ft_printf(GRN);
	printf("\nREAL RET->%d"RST"\n", printf("%p", &nbr));
*/
/*
	printf(PINK"------------ %%%% ------------"RST"\n");
	ft_printf(YELO);
	printf("\nMINE RET->%d\n", ft_printf("%3.2%"));
	ft_printf(GRN);
	printf("\nREAL RET->%d"RST"\n", printf("%3.2%"));
*/	
/*
	printf(PINK"------------ %%s ------------"RST"\n");
	char *strs = "p3 %s";
	char *strs2 = "bonjour";
	ft_printf(GREY"Testing: %s[END]"YELO"\n", strs);
	ft_printf(YELO);
	printf("\nMINE RET->%d\n", ft_printf(strs, strs2));
	ft_printf(GRN);
	printf("\nREAL RET->%d"RST"\n", printf(strs, strs2));
	*/
/*
printf(CYAN"------------ %%c ------------"RST"\n");
	char *str = "d: %10c[end]\n";
	char c = 'a';
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, c));
	
	
	int decal = 10;
	ft_printf(PINK);
	ft_putstr("d: %*c[end]\n");
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf("d: %*c[end]\n",decal, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf("d: %*c[end]\n", decal, c));
*/
/*
	printf(CYAN"------------ %%d ------------"RST"\n");
	char	*strd = "d: %46d\n";
	int		nbrd = 56;
	ft_printf(PINK);
	ft_putstr(strd);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(strd, nbrd));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(strd, nbrd));

	//printf("\nMINE RET->%d\n", ft_printf("%%%%%%"));
	//printf("\nREAL RET->%d\n", printf("%%%%%%"));
	//
	//printf("\nMINE RET->%d\n", ft_printf("%-1.0d", -1));
	//printf("\nREAL RET->%d\n", printf("%-1.0d", -1));
*/
/*
printf(CYAN"------------ %%p ------------"RST"\n");
	char *str = "d: %#p[end]\n";
//	char *str2 = "bonjour";

	char *str2 = ft_strdup("Bonjour comment ca va");
	//int str2 = 1000000000;
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, str2));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, str2));
	
	char *str2 = "d: %p[end]\n";
	ft_printf(PINK);
	ft_putstr(str2);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str2, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str2, c));
*/
/*
printf(CYAN"------------ %%x ------------"RST"\n");
	char *strx = "x: %0#*.*x[end]\n";

	int nbr = 0;
	ft_printf(PINK);
	ft_putstr(strx);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(strx, 5, 2, nbr));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(strx,5, 2, nbr));



printf(CYAN"------------ %%u ------------"RST"\n");
	char *stru = "u: %.*u[end]\n";
	unsigned int nbru = 2147483650;

	ft_printf(PINK);
	ft_putstr(stru);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(stru, 12, nbru));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(stru, 12, nbru));
*/
	return (0);
}
