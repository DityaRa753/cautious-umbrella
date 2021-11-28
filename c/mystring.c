#include<stdio.h>

int string_length1(const char *str)
{   
    const char *p;
    for(p = str; *p; p++)
        {}
    return p - str - 1;
}
int main() 
{
    char s[5] = {'H', 'e', 'l', 'l', 'o'};
    for(int i = 0; i <= 5; i++)
        printf("%c", *(s+i));
    printf("\n%d\n", string_length1(s));
}
/*          don't need to do that (!)        */
int string_length2(const char *str)
{
    const char *p = str;
    while(*p++);
    return p - str;
}
/*don't need to do that (!) */
int main1()
{
    char s[6] = {'J', 'o', 'h', 'a', 'n', 's'};
    for(int i = 0; i <= 6; i++)
        printf("%c", *(s+i));
    printf("\n%d\n", string_length2(s));
}
