#include "ft_printf.h"

void	work_on_flag(char *string)
{
	int i;
//	int dot;
//
//	dot = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '0' && flags.zero == 0)
		{
			flags.zero = 1;
			i++;
		}
		if (string[i] == '+')
			flags.plus = 1;
		if (string[i] == '-')
			flags.minus = 1;
		if (string[i] == '#')
			flags.hesh = 1;
		if (string[i] == ' ')
			flags.space = 1;
		if (string[i] == 'h')
		{
			if (string[i + 1] == 'h')
				flags.hh = 1;
			else
				flags.h = 1;
		}
		if (string[i] == 'l')
		{

			if (string[i + 1] == 'l')
			{
				flags.ll = 1;
				i++;
			}
			else
				flags.l = 1;
		}
		if (ft_isdigit(string[i])&& string[i] != '0' && string[i - 1] != '.')
			i += whats_width(string, i) - 1;
		if (string[i] == '.' && ft_isdigit(string[i + 1]))
			i += precision(string, i + 1) - 1;
		else if (ft_isalpha(string[i]))
			flags.type = string[i];
		i++;
	}
}
int 	whats_width(char *string, int i)
{
	char *num;
	int len;

	num = ft_memalloc(1);
	num[0] = '\0';
	while (ft_isdigit(string[i]))
	{
		num = ft_strjoin_for_one(num, &string[i]);
		i++;
	}
	len = ft_strlen(num);
	flags.width = ft_atoi(num);
	free(num);
	return (len);
}
int 	precision(char *string, int i)
{
	char *num;
	int len;

	num = "";
	while (!ft_isalpha(string[i]))
	{
		num = ft_strjoin_for_one(num, &string[i]);
		i++;
	}
	flags.precision = ft_atoi(num);
	len = ft_strlen(num);
	free(num);
	return (len);
}

char 	*get_this_flag(char *string, int i)
{
	char *new_str;
	int j;
	int size;

	j = i + 1;
	while (string[j] != 'c' && string[j] != 's' && string[j] != 'p' &&
			string[j] != 'd' && string[j] != 'i' && string[j] != 'o' &&
			string[j] != 'u' && string[j] != 'x' && string[j] != 'X' && string[j] != '%' && string[j])
		j++;
	size = j - i;
	if (string[j] == '%')
		size++;
	new_str = ft_memalloc(size + 1);
	j = 0;
	i++;
	while(j < size)
	{
		new_str[j] = string[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}