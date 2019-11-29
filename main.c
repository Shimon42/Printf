/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 18:04:58 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main(void)
{
	ft_putstr(RST);
	//ft_printf("%d", 1000);
	//ft_printf("%s", "Hello");
	/*ft_printf("");
	printf("");
	ft_printf(PINK"[Start]\n\t"CYAN"bonjour\n\
	per_s:"YELO" %s"CYAN"\n\
	per_d: "YELO"%d"CYAN"\n\
	per_ld: "YELO"%ld"CYAN"\n\
	per_lu: "YELO"%lu"CYAN"\n\
	per_c('a') -> "GRN"a"RST" vs "YELO"%c"CYAN"\n\
	per_o(8) -> "GRN"10"RST" vs "YELO"%o"CYAN"\n\
	per_x(14) -> "GRN"e"RST" vs "YELO"%x"CYAN"\n\
	salut\n"PINK"[end]\n"RST,\

	"couiiiiicou",\
	2147483647,\
	123,\
	123654654654,\
	'a',
	8,
	14);*/

	//printf("MINE RET->%d\n", ft_printf("d: % -5d end\n", 15));
	//printf("REAL RET->%d\n", printf("d: % -5d end\n", 15));

	//printf("MINE RET->%d\n", ft_printf("i: % -5i end\n", 033));
	//printf("REAL RET->%d\n", printf("i: % -5i end\n", 033));
	
	//printf(" -> MINE RET: %d\n", ft_printf("c: %-+ #05.10d[end]", 211));
	printf("%#+ 0 6.0%ok\n");
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
