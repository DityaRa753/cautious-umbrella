#include <stdio.h>

int convert_to_int(char* argv) {
    int num = 0;
    while (*argv) {
        num = num * 10 + *argv - '0';
        argv++;
    }
    return num;
}

int main(int argc, char* argv[]) 
{

    // if ((argv[1] >= 0 && argv[2] <= 20) && argv[1] + argv[2] > 0) {
        printf("%d\n", convert_to_int(argv[1]));
    // }
    return 0;
}