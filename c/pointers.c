#include<stdio.h>

int main() 
{
    int m[20];
    int *p;
    
    p = m;
    m[5] = 14;
    p[10] = 16;

    /* printf("%d\n%d\n", m[5], p[10]);*/
    /* printf("%d\n%d\n", *(m+5), *(p+10));*/
    printf("%d\n%d\n%s%d", 5[m], 10[p], "Размер 'массива' ", sizeof(m));

}
