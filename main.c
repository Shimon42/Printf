/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:35:12 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main(void)
{
	ft_putstr(RST);
/*
printf(CYAN"------------ %%s ------------"RST"\n");
	char *str = "d: %+ 35.s[end]\n";
	char *str2 = "Bonjour comment ça va";
	
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, str2));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, str2));
	
	char *str3 = "d: %0+ *.5s[end]\n";
	int decals = 35;

	ft_printf(PINK);
	ft_putstr(str3);
	ft_printf(YELO);

	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str3, decals, str2));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str3, decals, str2));
*/

printf(CYAN"------------ %%c ------------"RST"\n");
	char *str = "d: %10c[end]\n";
	char c = 'a';
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, c));
	
	char *str2 = "d: %0*.*c[end]\n";
	int decal = 10;
	ft_printf(PINK);
	ft_putstr(str2);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str2,decal,10, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str2, decal,10, c));


/*

	printf(CYAN"------------ %%d ------------"RST"\n");
	char	*str = "d: % -00*.*d[end]\n";
	int		nbr = -12;
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, nbr, -10, 12));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, nbr, -10, 12));
*/
	//printf("MINE RET->%d\n", ft_printf("i: % -5i end\n", 033));
	//printf("REAL RET->%d\n", printf("i: % -5i end\n", 033));
	
	//printf(" -> MINE RET: %d\n", ft_printf("c: %-+ #05.10d[end]", 211));
	//ft_printf("%6cok\n", 'a');
	//printf(" -> REAL RET: %d\n", printf("c: %5d end", 2111));
	/*
	int ok = 0;
	printf("REAL:%+-15ds\n", (ok = 13));
	ft_printf("MINE:%+-15ds\n", (ok = 13));
	ft_printf("MINEx: %+5d end\n", 125);
	printf("REALx: %+5d end\n", 125);

	//ft_putchar(128);
	ft_printf("MINE:%-15d end\n", 12);
	printf("REAL:%-15d end\n", 12);
	//printf("%o\n", 2147483647);
	//printf("%x\n", 14);
	int number = 12;
	printf(" %%*d: %*d\n", number, number);
    printf("%%04d: %04d\n", number);
    printf("%%-#5X: %-#5X end\n", number);  
    printf("%%-15x: %-15x end\n", number);  
    printf("%%#12x: %#12x \n", number);*/
	return (0);
}
