#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() 
{
    double *k;
    k = malloc(360 * sizeof(double));

    for(int i = 0; i < 360; i++)
        *(k+i) = sin((2*M_PI/360.0) * (double)i);
    for(int i = 0; i < 360; i++) {
         if(i % 15 == 0) {printf("\n");}
        printf("| %.2lf ", *(k+i));
    }
    /*FREE MEMMORY*/
    free(k);
}
