#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define KEK printf("KEK\n");
# define KEK2 printf("KEK2\n");

# include <stdio.h>

typedef struct 	s_flags
{
	int plus;
	int minus;
	int zero;
	int hesh;
	int space;
	int width;
	int precision;
	int hh;
	int ll;
	int l;
	int h;
	char type;
}				t_flags;

t_flags flags;
char 	*g_full_str;

int		ft_printf(char *string, ...);
void	for_numbers(char *string, int d);
void	for_string(char *str);
void	for_char(char c);
void	for_pointer(size_t x);
//ft_itoa
char	*ft_itoa(int num);
int		int_size(int n);
//help_func
int 	ft_width_for_int(char *string, int d);
char	*ft_strjoin_for_one(char const *s1, char const *s2);
//flags
int 	whats_width(char *string, int i);
void	work_on_flag(char *string);
char	*get_this_flag(char *string, int i);
int 	precision(char *string, int i);
//ft_itoa_base
char	*ft_itoa_base(size_t value, int base, int type);
char	*ft_reverse(char *str);
char	*ft_strcat_for_letter(char *s2, char *s1);
//wor_param
void	clean_param();
void 	work_on_param(va_list ap);
#endif
