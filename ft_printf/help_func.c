#include "ft_printf.h"

int 	ft_width_for_int(char *string, int d)
{
	int i;
	int width;
	char *str_width;
    int j;
	int save;

	i = 0;
	j = 0;
	while (string[i] != '.' && !ft_isalpha(string[i]))
	    i++;
	str_width = ft_memalloc(i);
	while (j < i)
    {
	    str_width[j] = string[j];
	    j++;
    }
    save = i;
	width = ft_atoi(str_width);
	if (width < 0)
		width = -width;
	width -= int_size(d);
	i = 0;
	if (width < int_size(d) && width > 0)
	{
		ft_putnbr(d);
		return(save);
	}
	else if (str_width[0] != '0' && str_width[0] != '-')
		while (i++ < width)
			g_full_str = ft_strjoin_for_one(g_full_str, " ");
	else if (str_width[0] == '0')
		while (i++ < width)
			g_full_str = ft_strjoin_for_one(g_full_str, "0");
	else if (str_width[0] == '-')
		while (i++ < width)
			g_full_str = ft_strjoin_for_one(g_full_str, " ");
	ft_strdel(&str_width);
	return save;
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