#include "ft_printf.h"

void	for_o(va_list ap)
{
	if (flags.hh)
		hh_o(va_arg(ap, int));
	else if (flags.h)
		h_o(va_arg(ap, int));
	else if (flags.l)
		l_o(va_arg(ap, unsigned long));
	else if (flags.ll)
		ll_o(va_arg(ap, unsigned long long));
	else
		no_diftype_o(va_arg(ap, int));
}

void hh_o(int x)
{
	unsigned char num;
	char *ful_num;

	num = x;
	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(num, 8, 1);
	make_all_for_o(ful_num);
	free(ful_num);
}

void h_o(int x)
{
	unsigned short num;
	char *ful_num;

	num = x;
	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(num, 8, 1);
	make_all_for_o(ful_num);
	free(ful_num);
}

void l_o(unsigned long x)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 8, 1);
	make_all_for_o(ful_num);
	free(ful_num);
}

void ll_o(unsigned long long x)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 8, 1);
	make_all_for_o(ful_num);
	free(ful_num);
}

void no_diftype_o(unsigned int x)
{
	char *ful_num;

	ful_num = ft_memalloc(1);
	ful_num[0] = '\0';
	ful_num = ft_itoa_base(x, 8, 1);
	make_all_for_o(ful_num);
	free(ful_num);
}

void make_all_for_o(char *num)
{
	if (flags.precision > ft_strlen(num))
		with_prec_o(num);
	else if (flags.width > ft_strlen(num) && flags.width > flags.precision)
		make_width_o(num);
	else {
		if (flags.hesh)
			g_full_str = ft_strjoin(g_full_str, "0x");
		g_full_str = ft_strjoin(g_full_str, num);
	}
}

void with_prec_o(char *num)
{
	char *buf;

	buf = ft_memalloc(1);
	buf[0] = '\0';
	make_prec_o(buf, num);
	free(buf);
}

void make_width_o(char *num)
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
void make_prec_o(char *str, char *d)
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
		make_width_o(str);
	else
	{
		g_full_str = ft_strjoin(g_full_str, str);
	}
}

