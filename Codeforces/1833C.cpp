/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define odd1(a) a&1

#define y "YES"
#define no "NO"


int main () {
    uint16_t t;
    uint32_t n;

    scanf("%hu", &t);


    for(int i=0 ; i<t; i++)
    {
        int64_t *a, min, odd;

        scanf("%u", &n);
        a = (int64_t *) malloc(n* sizeof(int64_t));

        for(int j=0 ; j<n; j++)
        {
            scanf("%lld", (a+j));
        }

        min = (int64_t) *(a);
        odd = 0;
        for(int j=1 ; j<n; j++)
        {
            if (min > *(a+j))
                min = *(a+j);
            if (odd1(*(a+j)))
                odd = 1;
        }

        if (!odd)
            printf("%s\n", y);
        else
        {
            if (odd1(min))
                printf("%s\n", y);
            else
                printf("%s\n", no);
        }
        free (a);
    }


   return 0;
}



