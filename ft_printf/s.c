#include "ft_printf.h"

void	for_s(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		g_full_str = ft_strjoin(g_full_str, "(null)");
	else if (flags.precision > 0 && flags.precision < ft_strlen(va_arg(ap, char *)))
		make_prec_s(str);
	else if (flags.width)
		make_width_s(str);
	else
		put_s(str);
}

void	make_prec_s(char *str)
{
	char *norm_str;
	int i;

	i = 0;
	norm_str = ft_memalloc(flags.precision);
	while (i < flags.precision)
	{
		norm_str[i] = str[i];
		i++;
	}
	if (flags.width > ft_strlen(str))
		make_width_s(norm_str);
	else
		put_s(norm_str);
}

void	make_width_s(char *str)
{
	int i;
	int len;

	i = -1;
	len = flags.width - ft_strlen(str);
	if (flags.minus)
	{
		put_s(str);
		flags.zero = 0;
	}
	if (flags.zero)
		while (++i < len)
			g_full_str = ft_strjoin(g_full_str, "0");
	else
		while (++i < len)
			g_full_str = ft_strjoin(g_full_str, " ");
	if (!flags.minus)
		put_s(str);
}

void	put_s(char *str)
{
	char *tmp;

	tmp = ft_memalloc(1);
	tmp[0] = '\0';
	g_full_str = ft_strjoin(g_full_str, str);
	free(tmp);
}