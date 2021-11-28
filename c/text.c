#include<stdio.h>

/* i DON'T understand how this program works... */

void inc(char *p) {printf("%c", p);p++;}

int main()
{
    char s[] = "Hello, world!\n";
    inc(s);
    printf("%s", s);
    printf("%d\n", sizeof(s));
    return 0;
}
