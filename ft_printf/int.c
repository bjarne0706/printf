#include "ft_printf.h"

void	for_numbers(char *string, int d)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '+' && d >= 0)
		{
			i = ft_width_for_int(string, d);
			g_full_str = ft_strjoin_for_one(g_full_str, "+");
			g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
			i++;
		}
		else if ((string[i] == '0' || string[i] == ' ') && string[i + 1] != '.' && !ft_isalpha(string[i + 1]))
		{
			i = ft_width_for_int(string, d);
			g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
		}
		else if (string[i] == '-' && string[i + 1] != '.')
		{
			g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
			i = ft_width_for_int(string, d);
		}
		else if (ft_isalnum(string[i]))
		{
			i = ft_width_for_int(string, d);
			g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
		}
		else if (string[i] == 'd' || string[i] == 'i')
		{
			g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
			i++;
		}
		i++;
	}
}

int	 flags_int(char *string, int d, int i)
{
	if (string[i] == '+' && d >= 0)
	{
		i = ft_width_for_int(string, d);
		g_full_str = ft_strjoin_for_one(g_full_str, "+");
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
		i++;
	}
	else if ((string[i] == '0' || string[i] == ' ') && string[i + 1] != '.' && !ft_isalpha(string[i + 1]))
	{
		i = ft_width_for_int(string, d);
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	}
	else if (string[i] == '-' && string[i + 1] != '.')
	{
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
		i = ft_width_for_int(string, d);
	}
	else if (ft_isalnum(string[i]))
	{
		i = ft_width_for_int(string, d);
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
	}
	else if (string[i] == 'd' || string[i] == 'i')
	{
		g_full_str = ft_strjoin(g_full_str, ft_itoa(d));
		i++;
	}
}

