/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 21:21:55 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/printf.h"
#include <limits.h>
int main(void)
{
	ft_putstr(RST);
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
