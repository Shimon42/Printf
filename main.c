#include "includes/libftprintf.h"
#include <stdio.h>
#include "includes/debug.h"

int main(void)
{
	ft_printf(PINK"[Start]\n\t"CYAN"bonjour\n\
	per_s:"YELO" %s"CYAN"\n\
	per_d: "YELO"%d"CYAN"\n\
	per_ld: "YELO"%ld"CYAN"\n\
	per_lu:  "YELO"%lu"CYAN"\n\
	per_c: "YELO"%c"CYAN"\n\
	salut\n"PINK"[end]"RST,\

	"couiiiiicou",\
	2147483647,\
	123,\
	123654654654,\
	'a');

	printf("%lu\n", 123654654654);
	return (0);
}
