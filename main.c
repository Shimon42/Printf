/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:34:00 by siferrar    ###    #+. /#+    ###.fr     */
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
	14);
	
	char * str= "d: %+010d[end]\n";
	int nbr = 1565;
	printf("MINE RET->%d\n", ft_printf(str, nbr));
	printf("REAL RET->%d\n", printf(str, nbr));
*/
/*
 //------------- %s ----------
	char *str = "d: % 0-6.5s[end]\n";
	char *str2 = "Bonjour comment ça va";
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, str2));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, str2));	
*/
/*
 //------------- %c ----------
	char *str = "d: %+ c[end]\n";
	char c = 'a';
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, c));
*/

 //------------ %d ------------
	char	*str = "d: % -.5d[end]\n";
	int		nbr = 12;
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, nbr));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, nbr));

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
