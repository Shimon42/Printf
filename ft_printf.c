#include <stdarg.h>
#include <stdio.h>

const char	*detect_param(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i - 1] != '\\')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	va_list va;

	va_start (va, str);
	char *res = va_arg (va, char *);
	printf("%s\n", res);
	printf("Found %s\n", detect_param(str));
	/* traitement des paramètres selon la fonction */ 
	va_end (va);
	return (1);
}
