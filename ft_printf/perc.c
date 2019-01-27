#include "ft_printf.h"

void	for_perc()
{
	if (flags.minus)
		flags.zero = 0;
	if (flags.precision)
		with_prec_perc("%");
	else if (flags.width > flags.precision)
		make_width_ll_d("%");
	else
		g_full_str = ft_strjoin(g_full_str, "%");
}

void with_prec_perc(char *perc)
{
	char *buf;

	buf = ft_memalloc(1);
	buf[0] = '\0';
	make_prec_perc(buf, perc);
	free(buf);
}

void make_prec_perc(char *str, char *d)
{
	int i;
	int len;

	len = flags.precision - ft_strlen(d);
	i = 0;
	while (i++ < len)
		str = ft_strjoin_for_one(str, "0");
	str = ft_strjoin(str, d);
	if (flags.width > ft_strlen(str))
		make_width_perc(str);
	else
		g_full_str = ft_strjoin(g_full_str, str);
}

void make_width_perc(char *str)
{
	int i;
	int len;
	char *buf;

	len = flags.width - ft_strlen(str);
	i = 0;
	buf = ft_memalloc(1);
	buf[0] = '\0';
	if (flags.plus)
		len--;
	if (flags.minus && flags.plus)
	{
		buf = ft_strjoin_for_one(buf, "+");
		buf = ft_strjoin(buf, str);
	}
	else if (flags.minus)
		buf = ft_strjoin(buf, str);
	if (flags.zero && !flags.plus)
	{
		while (i++ < len)
			buf = ft_strjoin_for_one(buf, "0");
	}
	else
	{
		while (i++ < len)
			buf = ft_strjoin_for_one(buf, " ");
	}
	if (flags.plus && !flags.minus)
		buf = ft_strjoin_for_one(buf, "+");
	if (!flags.minus)
		buf = ft_strjoin(buf, str);
	g_full_str = ft_strjoin(g_full_str,buf);
	free(buf);
}

