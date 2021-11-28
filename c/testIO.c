#include<stdio.h>

int main ()
{
    char c, n = 0; 
    while((c = getchar()) != EOF){
        if(c == 10) {
            printf("Ok\n%d\n", n);
            n = 0;
        } else {
            n++;
        }
    }
    return 0;
}
