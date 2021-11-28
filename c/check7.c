#include<stdio.h>

int main()
{
    enum colors {red, green, blue};
    printf("%d\n", green);
    /* ERROR
    green = 10;
    printf("%d\n", green);
    */
}
