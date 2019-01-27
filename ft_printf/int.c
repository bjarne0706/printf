#include "ft_printf.h"

void	for_di(va_list ap)
{
	if ((flags.hesh && flags.precision != 0) || flags.plus)
		flags.zero = 0;
	if (flags.hh)
		hh_d(va_arg(ap, int));
	else if (flags.h)
		h_d(va_arg(ap, int));
	else if (flags.ll)
		ll_d(va_arg(ap, int));
	else if (flags.l)
		l_d(va_arg(ap, int));
	else
		no_diftype_d(va_arg(ap, int));
}

void hh_d(char d)
{

}

void h_d(short d)
{
	int sign;

	if (d < 0)
	{
		g_full_str = ft_strjoin_for_one(g_full_str, "-");
		d = -d;
		sign = 1;
		flags.width = flags.width - 1;
		if (flags.plus)
			flags.plus = 0;
	}
	if (flags.precision > int_size(d))
		with_prec_ll_d(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_d(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
}

void ll_d(long long d)
{
	int sign;

	if (d < 0)
	{
		g_full_str = ft_strjoin_for_one(g_full_str, "-");
		d = -d;
		sign = 1;
		flags.width = flags.width - 1;
		if (flags.plus)
			flags.plus = 0;
	}
	if (flags.precision > int_size(d))
		with_prec_ll_d(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_d(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
}

void l_d(long d)
{
	int sign;
	char *tmp;

	if (d < 0)
	{
		tmp = g_full_str;
		g_full_str = ft_strjoin_for_one(g_full_str, "-");
		d = -d;
		sign = 1;
		flags.width = flags.width - 1;
		if (flags.plus)
			flags.plus = 0;
	}
	if (flags.precision > int_size(d))
		with_prec_ll_d(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_d(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	free(tmp);
}

void no_diftype_d(int d)
{
	int sign;

	if (flags.minus)
		flags.zero = 0;
	if (d < 0 && (flags.zero || flags.precision != 0))
	{
		d = -d;
		sign = 1;
		flags.width = flags.width - 1;
		if (flags.plus)
			flags.plus = 0;
	}

	if (flags.precision > int_size(d))
		with_prec_ll_d(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_d(ft_itoa(d));
	else
	{
		if (flags.plus && d > 0)
			g_full_str = ft_strjoin(g_full_str, "+");
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	}

}

void with_prec_ll_d(char *d, int sign)
{
	char *buf;

	buf = ft_memalloc(1);
	buf[0] = '\0';
	make_prec_ll_d(buf, d, sign);
	free(buf);
//	make_width_ll_d();
}

void make_prec_ll_d(char *str, char *d, int sign)
{
	int i;
	int len;

	len = flags.precision - ft_strlen(d);
	i = 0;
	if (sign)
	{
		str = ft_strjoin_for_one(str, "-");
	}
	while (i++ < len)
		str = ft_strjoin_for_one(str, "0");
	str = ft_strjoin(str, d);
	if (flags.width >= ft_strlen(str))
		make_width_ll_d(str);
	else
	{
		g_full_str = ft_strjoin(g_full_str, str);
//		g_full_str = ft_strjoin(g_full_str, d);
	}
}

void make_width_ll_d(char *str)
{
	int i;
	int len;
	char *buf;

	len = flags.width - ft_strlen(str);
	i = 0;
	buf = "";
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
}