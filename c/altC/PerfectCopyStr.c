#include<stdio.h>

void mstrcpy(char *dest, const char *src)
{
    while((*dest++ = *src++)); /* HA! Clever! */
}

int lengthstring(const char *src)
{
    const char *pnt = src;
    while(*pnt++); /* don't to do that... */
    return (pnt - 1) - src;
}

int main()
{
    char s[] = {'H', 'u', 'e', 0}; 
    int len = sizeof(s) / sizeof(*s);
    char s2[len];
    //printf("%ld %ld %d\n", sizeof(s), sizeof(*s), *(s+1));
    for(int i = 0; i < len; i++) {
        printf("%c", s[i]);
        printf("%d ", s[i]);
    }
    printf("\n");
    /*for(int i = 0; i < len; i++)
        printf("%d ", (unsigned char)s[i]);*/

    printf("Copy old string\n");
    mstrcpy(s2, s);
    
    for(int i = 0; i < len; i++) {
        printf("%c", s2[i]);
        printf("%d ", s2[i]);    
    }
    printf("\n");
    printf("len first string -> %d\n", lengthstring(s));
    printf("len two string -> %d\n", lengthstring(s2));
}
