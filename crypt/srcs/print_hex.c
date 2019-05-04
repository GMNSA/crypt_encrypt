/* print_hex.c */

#include "../includes/tools.h"

void        print_hex(int num)
{
    if (num >= 16)
        print_hex(num / 16);
    num %= 16;
    num += (num < 10) ? '0' : 87;
    putchar(num);
}
