#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6

void expression(int* a, int S, int result)
{
   char o[S - 1];

    int r;
    for (int i = 0; i < pow(4, S - 1); ++i) {
        r = a[0];
        int p = 1;//4^(j - 1)
        for (int j = 1; j < S; ++j) {
            switch ((i / p) % 4) {
            case 0:
                r += a[j];
                o[j - 1] = '+';
                break;
            case 1:
                r -= a[j];
                o[j - 1] = '-';
                break;
            case 2:
                r *= a[j];
                o[j - 1] = '*';
                break;
            case 3:
                r /= a[j];
                o[j - 1] = '/';
                break;
            }
            p *= 4;
        }
        if (r == result) {
            printf("((((%d ", a[0]);
            for (int k = 1; k < S; ++k)
                printf("%c %d ) ", o[k - 1], a[k]);
            printf("= %d\n", result);
        }
    }
}


int main()
{
   int a[N] = { 1, 2, 3, 4, 5, 6, };
   expression(a, N, 35);


   return 0;
}



