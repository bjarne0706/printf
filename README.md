# ft_printf

The aim of this project was to mimic the original C standart library function - [printf](https://en.wikipedia.org/wiki/Printf)

Subject - [en.subject_ft_printf.pdf](https://github.com/user-attachments/files/18694722/en.subject_ft_printf.pdf)

## Usage

``make`` - to compile a library

### ft_printf() flags:

• ``%c`` Prints a single character.

• ``%s`` Prints a string (as defined by the common C convention).

• ``%p`` The void * pointer argument has to be printed in hexadecimal format.

• ``%d`` Prints a decimal (base 10) number.

• ``%i`` Prints an integer in base 10.

• ``%u`` Prints an unsigned decimal (base 10) number.

• ``%x`` Prints a number in hexadecimal (base 16) lowercase format.

• ``%X`` Prints a number in hexadecimal (base 16) uppercase format.

• ``%%`` Prints a percent sign.

To use a library, import header:

```C
#include "ft_printf.h"
```
