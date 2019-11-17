#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list va;

	va_start (va, str);
	/* traitement des paramètres selon la fonction */ 
	va_end (va);
	return (1);
}
