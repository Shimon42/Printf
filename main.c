/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: siferrar <siferrar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:23:48 by siferrar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 17:52:39 by siferrar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main(void)
{
	ft_putstr(RST);

	printf(PINK"------------ %%s ------------"RST"\n");
	char *strs = "p3 %s";
	//char *strs2 = "bonjour";
	ft_printf(GREY"Testing: %s[END]"YELO"\n", strs);

	
	ft_printf(YELO);
	printf("\nMINE RET->%d\n", ft_printf(strs, NULL));
	ft_printf(GRN);
	//printf("\nREAL RET->%d"RST"\n", printf(strs, strs2));
	printf("\nREAL RET->%d"RST"\n", printf(strs, NULL));
	
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
	
	char *str2 = "d: %0*.*c[end]\n";
	int decal = 10;
	ft_printf(PINK);
	ft_putstr(str2);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str2,decal,10, c));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str2, decal,10, c));
*/



	printf(CYAN"------------ %%d ------------"RST"\n");
	char	*strd = "d: %46d[end]\n";
	int		nbrd = 0;
	ft_printf(PINK);
	ft_putstr(strd);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(strd, nbrd));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(strd, nbrd));

	printf("MINE RET->%d\n", ft_printf("%% %% %%"));
	printf("REAL RET->%d\n", printf("%% %% %%"));
	printf("%x\n", -1);

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
	char *str = "x: %0#*.*x[end]\n";

	int nbr = 0;
	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, 5, 2, nbr));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str,5, 2, nbr));
*/

/*
printf(CYAN"------------ %%u ------------"RST"\n");
	char *str = "u: %.*u[end]\n";
	unsigned int nbr = 2147483650;

	ft_printf(PINK);
	ft_putstr(str);
	ft_printf(YELO);
	printf("MINE RET->%d\n", ft_printf(str, 12, nbr));
	ft_printf(GRN);
	printf("REAL RET->%d"RST"\n", printf(str, 12, nbr));
*/
	return (0);
}
