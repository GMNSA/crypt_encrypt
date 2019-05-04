/* print_bit.c */

#include "../includes/tools.h"

void    print_bit(uchar n)
{
    int     i;

    i = 7;
    while (i >= 0)
    {
        putchar(((n >> i) & 0x01) + '0');
        --i;
    }
}
