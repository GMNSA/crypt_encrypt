/* print_bits.c */

#include "../includes/tools.h"

void    print_bits(uchar size, void const* num)
{
    uchar   *b;
    char    i;
    char    j;
    uchar   byte;

    b = (uchar*) num;
    i = (size - 1);
    while (i >= 0)
    {
        j = 7;
        while (j >= 0)
        {
            byte = (b[i + 0] >> j) & 0x01;
            putchar(byte + '0');
            --j;
        }
        --i;
        putchar(' ');
    }
}
