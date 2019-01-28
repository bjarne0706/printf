#include "ft_printf.h"

void	for_x(va_list ap, int sign)
{
	if (flags.hh)
		hh_x(va_arg(ap, int), sign);
	else if (flags.h)
		h_x(va_arg(ap, int), sign);
	else if (flags.l)
		l_x(va_arg(ap, unsigned long), sign);
	else if (flags.ll)
		ll_x(va_arg(ap, unsigned long long), sign);
	else
		no_diftype_x(va_arg(ap, int), sign);
}

void hh_x(int x, int sign)
{
	unsigned char num;
	char *ful_num;

	num = x;
	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(num, 16, sign);
	make_all_for_x(ful_num);
	free(ful_num);
}

void h_x(int x, int sign)
{
	unsigned short num;
	char *ful_num;

	num = x;
	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(num, 16, sign);
	make_all_for_x(ful_num);
	free(ful_num);
}

void l_x(unsigned long x, int sign)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 16, sign);
	make_all_for_x(ful_num);
	free(ful_num);
}

void ll_x(unsigned long long x, int sign)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 16, sign);
	make_all_for_x(ful_num);
	free(ful_num);
}

void no_diftype_x(unsigned int x, int sign)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 16, sign);
	make_all_for_x(ful_num);
	free(ful_num);
}

void make_all_for_x(char *num)
{
	if (flags.precision > ft_strlen(num))
		with_prec_x(num);
	else if (flags.width > ft_strlen(num) && flags.width > flags.precision)
		make_width_x(num);
	else {
		if (flags.hesh && num[0] != '0')
			g_full_str = ft_strjoin(g_full_str, "0x");
		g_full_str = ft_strjoin(g_full_str, num);
	}
}

void with_prec_x(char *num)
{
		char *buf;

		buf = ft_memalloc(1);
		buf[0] = '\0';
		make_prec_x(buf, num);
		free(buf);
}

void make_width_x(char *num)
{
	int i;
	int len;
	char *buf;

	len = flags.width - ft_strlen(num);
	i = 0;
	buf = "";
	if (flags.minus)
		flags.zero = 0;
	if (flags.hesh)
		len-=2;
	if (flags.hesh && flags.minus)
	{
		buf = ft_strjoin(buf, "0x");
		buf = ft_strjoin(buf, num);
		flags.hesh = 0;
	}
	else if (flags.minus)
		buf = ft_strjoin(buf, num);
	if (flags.hesh && flags.zero)
	{
		buf = ft_strjoin(buf, "0x");
		flags.hesh = 0;
	}
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
	if (flags.hesh)
	{
		buf = ft_strjoin(buf, "0x");
		flags.hesh = 0;
	}
	if (!flags.minus)
		buf = ft_strjoin(buf, num);
	g_full_str = ft_strjoin(g_full_str,buf);
}
void make_prec_x(char *str, char *d)
{
	int i;
	int len;

	len = flags.precision - ft_strlen(d);
	i = 0;
	if (flags.hesh)
		str = ft_strjoin(str, "0x");
	while (i++ < len)
		str = ft_strjoin_for_one(str, "0");
	str = ft_strjoin(str, d);
	if (flags.width >= ft_strlen(str))
		make_width_x(str);
	else
	{
		g_full_str = ft_strjoin(g_full_str, str);
	}
}