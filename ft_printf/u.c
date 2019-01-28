#include "ft_printf.h"

void	for_u(va_list ap)
{
	if ((flags.hesh && flags.precision != 0) || flags.plus)
		flags.zero = 0;
	if (flags.hh)
		hh_u(va_arg(ap, int));
	else if (flags.h)
		h_u(va_arg(ap, int));
	else if (flags.ll)
		ll_u(va_arg(ap, unsigned long long));
	else if (flags.l)
		l_u(va_arg(ap, unsigned long));
	else
		no_diftype_u(va_arg(ap, int));
}

void hh_u(unsigned char d)
{
	int sign;

	sign = 0;
	if (flags.precision > int_size(d))
		with_prec_ll_u(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_u(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
}

void h_u(unsigned short d)
{
	int sign;

	sign = 0;
	if (flags.precision > int_size(d))
		with_prec_ll_u(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_u(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
}

void ll_u(unsigned long long d)
{
	int sign;

	sign = 0;
	if (flags.precision > int_size(d))
		with_prec_ll_u(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_u(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
}

void l_u(unsigned long d)
{
	int sign;
	char *tmp;

	sign = 0;
	tmp = ft_memalloc(1);
	tmp[0] = '\0';
	if (flags.precision > int_size(d))
		with_prec_ll_u(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_u(ft_itoa(d));
	else
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	if (tmp)
		free(tmp);
}

void no_diftype_u(unsigned int d)
{
	int sign;

	sign = 0;
	if (flags.minus)
		flags.zero = 0;
	if (flags.precision > int_size(d))
		with_prec_ll_u(ft_itoa(d), sign);
	else if (flags.width > int_size(d) && flags.width > flags.precision)
		make_width_ll_u(ft_itoa(d));
	else
	{
		if (flags.plus)
			g_full_str = ft_strjoin(g_full_str, "+");
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	}

}

void with_prec_ll_u(char *d, int sign)
{
	char *buf;

	buf = ft_memalloc(1);
	buf[0] = '\0';
	make_prec_ll_u(buf, d, sign);
	free(buf);
//	make_width_ll_u();
}

void make_prec_ll_u(char *str, char *d, int sign)
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
		make_width_ll_u(str);
	else
	{
		g_full_str = ft_strjoin(g_full_str, str);
//		g_full_str = ft_strjoin(g_full_str, d);
	}
}

void make_width_ll_u(char *str)
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

