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
	g_full_str = ft_memalloc(1);
	g_full_str[0] = '\0';
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
		{
			g_temp = g_full_str;
			g_full_str = ft_strjoin_for_one(g_full_str, &string[i]);
			free(g_temp);
		}
		i++;
	}
	va_end(ap);
	ft_putstr(g_full_str);
	size = ft_strlen(g_full_str);
	free(g_full_str);
	return (size);
}


void	for_p(va_list ap)
{
	char *adr;
	char *fin_adr;

	fin_adr = "0x";
	adr = ft_itoa_base(va_arg(ap, int *), 16, 1);
	fin_adr = ft_strjoin(fin_adr, adr);
	g_full_str = ft_strjoin(g_full_str, fin_adr);
	ft_strdel(&adr);
	ft_strdel(&fin_adr);
}


void	for_c(va_list ap)
{
	g_full_str = ft_strjoin_for_one(g_full_str, va_arg(ap, char *));
}

char		*ft_strjoin_for_one(char const *s1, char const *s2)
{
	char	*s_new;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(s_new = ft_memalloc(i + 1)))
		return (NULL);
	ft_strcat(s_new, (char *)s1);
	ft_strcat_for_letter(s_new, (char *)s2);
	s_new[i + 1] = '\0';
	return (s_new);
}