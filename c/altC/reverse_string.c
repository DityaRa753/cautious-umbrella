#include <stdio.h>

void swap(char* sym1, char* sym2)
{
    *sym1 = *sym1 + *sym2;
    *sym2 = *sym1 - *sym2;
    *sym1 = *sym1 - *sym2;
}

void reversestr(const char* strfrom, char* strdest, int strlen)
{
    int chr = strlen-2; // the letters themselvesm always 2 less.
    for (int i = 0; i < strlen; i++) {
        strdest[i] = strfrom[chr--];
    }
    strdest[strlen-1] = 0;
}

int main(int ac, char const * const *av)
{
    char str[] = "tenet1";
    int len = sizeof str;
    char revstr[len];
    char* g = revstr;
    printf("This string(%d) -> %s\n\n", len, str);
    reversestr(str, revstr, len);
    printf("and this reverse string -> %s\n\n", revstr);
    while (*g) {
        printf("%c-%d ",*g, *g);
        g++;
    }
    printf("\n");
    return 0;
}
