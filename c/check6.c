#include<stdio.h>

void print_size(int qty, char *type)
{
    printf("%ld\n", qty * (sizeof(*type)));
}

int main()
{
    char buff[1024];
    print_size(1024, buff[0]);
    printf("%ld\n", sizeof buff);
}
