#include<stdio.h>

void string_copy(char *dest, const char *src)
{
    int i;
    for(i = 0; *(src+i); i++)
        *(dest+i) = *(src+i);
     *(dest+i) = 0;
}

int main()
{
    char s[] = {'D', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
    int l = sizeof(s)/sizeof(*s);
    char s2[l];
    for(int i = 0; i < l; i++)
        printf("%c", *(s+i));
    printf("\n");
    for(int i = 0; i < l; i++) {
        *(s2+i) = '9';
        printf("%c", *(s2+i));
    }
    /*printf("\n%c\n", *(s+10));*/
    printf("\nCopy Up string\n");
    
    string_copy(s2, s);

    for(int i = 0; i < l; i++) {
        printf("%c", *(s2+i));
    }
    printf("\n");
    /* printf("%c\n", s2[l]); */
}
