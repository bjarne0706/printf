#include "ft_printf.h"

char	*ft_itoa_base(size_t value, int base, int type)
{
	char *numb;
	int ost;
	int i;
	char c;

	numb = ft_strnew(int_size(value));
	i = 0;
	while (value)
	{
		ost = value % base;
		value = value / base;
		if (ost > 9)
		{
			if (type)
				c = (ost - 9) + '`';
			else
				c = (ost - 9) + '@';
			ft_strcat_for_letter(numb, &c);
		}
		else if (ost == 0)
			ft_strcat_for_letter(numb, "0");
		else
			ft_strcat_for_letter(numb, ft_itoa(ost));
		i++;
	}
	numb = ft_reverse(numb);
	return (numb);
}

char	*ft_reverse(char *str)
{
	int i;
	int sign;
	char c;

	i = 0;
	sign = ft_strlen(str) - 1;
	while (i < sign) {
		c = str[i];
		str[i] = str[sign];
		str[sign] = c;
		i++;
		sign--;
	}
	return (str);
}

char	*ft_strcat_for_letter(char *s2, char *s1)
{
	int i;

	i = ft_strlen(s2);
	s2[i] = s1[0];
	s2++;
	s2[i] = '\0';
	return (s2);
}
