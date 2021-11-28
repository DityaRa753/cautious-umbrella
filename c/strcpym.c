#include<stdio.h>

void string_copy(char *dest, const char *src)
{
    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
}

/* maybe better... upd: very much better (!) */
void string_copy2(char *dest, const char *src)
{
    for(; *src; dest++, src++)
        *dest = *src;
    *dest = 0;
}


int main()
{
    char s[] = {'C', 'o', 'p', 'y', '!'};
    int len  = sizeof(s) / sizeof(*s);
    char s2[len];

    for(int i = 0; i < len; i++)
        printf("%c", *(s+i));
    printf("\n");
    
    string_copy2(s2, s);

    for(int i = 0; i < len; i++)
        printf("%c", *(s2+i));
    printf("\n");

}
