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
//global
t_flags flags;
char 	*g_full_str;
char 	*g_temp;
//ft_printf
int		ft_printf(char *string, ...);
void	for_s(va_list(ap));
void	for_c(va_list(ap));
void	for_p(va_list(ap));
void	for_o(va_list(ap));
void	for_u(va_list(ap));
void	for_x(va_list(ap));
void	for_X(va_list(ap));
char	*ft_strjoin_for_one(char const *s1, char const *s2);
//ft_itoa
char	*ft_itoa(long long num);
int		int_size(long long n);

//flags
int 	whats_width(char *string, int i);
void	work_on_flag(char *string);
char	*get_this_flag(char *string, int i);
int 	precision(char *string, int i);
//ft_itoa_base
char	*ft_itoa_base(size_t value, int base, int type);
char	*ft_reverse(char *str);
char	*ft_strcat_for_letter(char *s2, char *s1);
//work_param
void	clean_param();
void 	work_on_param(va_list ap);
//int
void	for_di(va_list ap);
void	hh_d(char d);
void	h_d(short d);
void	ll_d(long long d);
void	l_d(long d);
void	no_diftype_d(int d);
void	with_prec_ll_d(char *d, int sign);
void	make_prec_ll_d(char *str, char *d, int sign);
void	make_width_ll_d(char *str);
//perc
void	for_perc();
void	with_prec_perc(char *perc);
void	make_prec_perc(char *str, char *d);
void	make_width_perc(char *str);
#endif
