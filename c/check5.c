#include<stdio.h>

int main()
{
    char str[33];
    int cnt;
    cnt = sprintf(str, "%s %d %c", "one", 2, '3'); /* writing in array, i.e buffer */
    printf("size of the entered value - %d\n", cnt);
    /* including "zero" byte */
    for(int i = 0; i < 33; i++) { 
        if(str[i] > 255) break; else
            if(str[i] == 0) break;
        printf("(%c)", str[i]);
        printf("[%d]", str[i]);
    }
    printf("\n");
}
