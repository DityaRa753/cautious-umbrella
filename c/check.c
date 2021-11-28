#include<stdio.h>

int main()
{
    char str[] = "Hello";
    char *ptr = "Hello";

    printf("%s\n%c\n", str, *ptr);
    printf("%c\n", *(ptr+1));
    
    /* CHANGE! */
    str[2] = 'J';
    ptr[4] = 0; /*don't use! It's not work!*/
    printf("%s\n", str);
}
