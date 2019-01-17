#include "ft_printf.h"

void	clean_param()
{
	flags.minus = 0;
	flags.plus = 0;
	flags.zero = 0;
	flags.hesh = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.type = 0;
}
void 	work_on_param(va_list ap)
{
	if (flags.type == 'd')

}

