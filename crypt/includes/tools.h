/* tools.h */

#ifndef TOOLS_H
#define TOOLS_H

typedef unsigned char   uchar;
typedef unsigned int    uint;
typedef unsigned short  ushort;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

# define N      4

void        print_bit(uchar n);
void        print_bits(uchar size, void const* num);
void        print_hex(int num);
void        shuffle(int *arr, int n);
uint        crypt_password(uchar A, uchar B, uchar C, uchar D);

#endif
