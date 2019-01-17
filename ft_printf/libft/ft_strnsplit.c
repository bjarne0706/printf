/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchantse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:07:10 by dchantse          #+#    #+#             */
/*   Updated: 2018/12/28 17:38:49 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c, size_t i)
{
	size_t		j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char			**ft_strnsplit(char const *s, int i, int end, char c)
{
	size_t		word_num;
	char		**parsed;
	int			j;

	word_num = -1;
	if (s)
	{
		if (!(parsed = ft_memalloc(sizeof(char**) * ft_word_count(s, c) + 1)))
			return (NULL);
		while (++word_num < ft_word_count(s, c) && i < end)
		{
			while (s[i] == c && i < end)
				i++;
			parsed[word_num] = ft_strnew(word_len(s, c, i));
			j = 0;
			while (s[i] != c && s[i] && i < end)
				parsed[word_num][j++] = s[i++];
			parsed[word_num][j] = '\0';
		}
		parsed[word_num] = NULL;
		return (parsed);
	}
	return (NULL);
}
