/* crypt_password.c */

#include "../includes/tools.h"

ushort      pwd_crypt(int *box, int size, uchar A, uchar B, uchar C, uchar D);
uchar       order_crypt(int *box, int size);
uint        crypt_password(uchar A, uchar B, uchar C, uchar D);
uint        packaging(uchar order, ushort password);

ushort      pwd_crypt(int *box, int size, uchar A, uchar B, uchar C, uchar D)
{
    short temp = 0;
    int     a = 12;

    for (int i = 0; i < size; ++i)
    {
        if (box[i] == 0 && i == 0)
            temp = temp | A << 12;
        else if (box[i] == 1 && i == 0)
            temp = temp | B << 12;
        else if (box[i] == 2 && i == 0)
            temp = temp | C << 12;
        else if (box[i] == 3 && i == 0)
            temp = temp | D << 12;

        if (box[i] == 0 && i == 1)
            temp = temp | A << 8;
        else if (box[i] == 1 && i == 1)
            temp = temp | B << 8;
        else if (box[i] == 2 && i == 1)
            temp = temp | C  << 8;
        else if (box[i] == 3 && i == 1)
            temp = temp | D << 8;

        if (box[i] == 0 && i == 2)
            temp = temp | A << 4;
        else if (box[i] == 1 && i == 2)
            temp = temp | B << 4;
        else if (box[i] == 2 && i == 2)
            temp = temp | C  << 4;
        else if (box[i] == 3 && i == 2)
            temp = temp | D << 4;

        if (box[i] == 0 && i == 3)
            temp = temp | A;
        else if (box[i] == 1 && i == 3)
            temp = temp | B;
        else if (box[i] == 2 && i == 3)
            temp = temp | C;
        else if (box[i] == 3 && i == 3)
            temp = temp | D;
        a -= 4;
    }
    return (temp);
}

uchar       order_crypt(int *box, int size)
{
    uchar   res = 0;
    char    a = 6;
    int     tmp = 3;

    for (int i = 0; i < size; i++)
    {
        res = res | (tmp & box[i]) << (a + 0);
        a -= 2;
    }
    return (res);
}

uint        packaging(uchar order, ushort password)
{
    srand(time(NULL));

    int         i = rand() % 4;
    int         box[N];
    uchar       trash = 0;
    uint        result = 0;

    if (i == 2)
        box[2] = 3; // 0011
    else
        box[2] = i; // ????

    box[0] = 0; // 0000
    box[1] = 1; // 0001
    box[3] = 3; // 0011

    shuffle(box, N);
    trash = order_crypt(box, N);
    if (i == 1 || i == 3)
    {
        result = result | trash << 24;
        result = result | password << 8;
        result = result | order;
    }
    else
    {
        result = result | order << 24;
        result = result | password << 8;
        result = result | trash;
    }
    return (result);
}

uint        crypt_password(uchar A, uchar B, uchar C, uchar D)
{
    int         box[N];
    uint        result = 0;
    uchar       order;
    ushort      pwd;

    box[0] = 0; // 0000
    box[1] = 1; // 0001
    box[2] = 2; // 0010
    box[3] = 3; // 0011

    shuffle(box, N);
    order = order_crypt(box, N);
    pwd = pwd_crypt(box, N, A, B, C, D);
    result = packaging(order, pwd);
    return (result);
}
