#include "includes/libftprintf.h"
#include "includes/libft/libft.h"
#include <stdio.h>
#include "includes/debug.h"

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


	int ok = 0;
	printf("%d\n", (ok = 13));
	ft_printf("MINEx: %+5d end\n", 125);
	printf("REALx: %+d end\n", 125);

	//ft_putchar(128);
	ft_printf("MINE:%-175d end\n", 12);
	printf("REAL:%-175d end\n", 12);
	//printf("%o\n", 2147483647);
	//printf("%x\n", 14);
	int number = 12;
	printf(" %%*d: %*d\n", number, number);
    printf("%%04d: %04d\n", number);
    printf("%%-#5x: %-#5x end\n", number);  
    printf("%%-15x: %-15x end\n", number);  
    printf("%%#12x: %#12x \n", number);
	return (0);
}
