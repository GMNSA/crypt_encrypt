/* main.c */

#include "../includes/tools.h"

int     main(void)
{ 
    uint res = crypt_password(4, 8, 3, 1);
    print_bits(sizeof(res), &res);

    return (0);
}

