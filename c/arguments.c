#include<stdio.h>

int main(argc, argv)
    int argc;
    char **argv;
{
    while(*++argv) {
        printf("[%s]\n", *argv);
    }
}
