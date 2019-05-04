/* shuffle.c */

#include "../includes/tools.h"

void    shuffle(int *arr, int n)
{
    int   i;
    int   j;
    int     temp;

    srand(time(NULL));

    i = n - 1;
    while (i >= 1)
    {
        j = rand() % (i + 1);
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        --i;
    }
}
