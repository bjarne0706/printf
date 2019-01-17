/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchantse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:01:08 by dchantse          #+#    #+#             */
/*   Updated: 2019/01/04 18:02:23 by dchantse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *string, ...)
{
    va_list ap;
    int i;
	char *flag;
	int size;

	i = 0;
	g_full_str = "";
	va_start(ap, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			flag = get_this_flag(string, i);
			i += ft_strlen(flag);
			work_on_flag(flag);
			work_on_param(ap);
			clean_param();
			ft_strdel(&flag);
		}
		else
			g_full_str = ft_strjoin_for_one(g_full_str, &string[i]);
		i++;
	}
	va_end(ap);
	ft_putstr(g_full_str);
	size = ft_strlen(g_full_str);
	ft_strdel(&g_full_str);
	return (size);
}

void	for_string(char *s)
{
	g_full_str = ft_strjoin(g_full_str, s);
}
void	for_pointer(size_t x)
{
	char *adr;
	char *fin_adr;

	fin_adr = "0x";
	adr = ft_itoa_base(x, 16, 1);
	fin_adr = ft_strjoin(fin_adr, adr);
	g_full_str = ft_strjoin_for_one(g_full_str, fin_adr);
	ft_strdel(&adr);
	ft_strdel(&fin_adr);
}


void	for_char(char c)
{
	g_full_str = ft_strjoin_for_one(g_full_str, &c);
}