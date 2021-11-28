#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int val[] = {
    1, 4, 5, 9, 10, 40, 50, 90, 
    100, 400, 500, 900, 1000
};
const char **roman_literals[] = {
    "I", "IV", "V", "IX", "X", "XL",
    "L", "XC", "C", "CD", "D", "CM", "M"
};

char *solution(int number)
{
    int len = 0;
    char *rome = NULL;
    for(int i = (sizeof val / sizeof *val)-1; i >= 0; i--)
    while (number >= val[i]) {
        // printf("%d - %d ->  %s(%d)\n", number, val[i], roman_literals[i], i);
        number -= val[i];
        if(len == 0) {
            rome = calloc(strlen(roman_literals[i]), sizeof *rome);
        } else {
            rome = realloc(rome, strlen(roman_literals[i]) + len);
        }
        strcat(rome, roman_literals[i]);
        len = strlen(rome);
        // printf("%s %d\n", rome, len);
    }
    return rome;
}

int main()
{
    // char **tmp = roman_literals;
    // for(int i = 0; tmp[i]; i++) {
    //     for (int j = 0; tmp[i][j]; j++) {
    //         printf("%c", tmp[i][j]);
    //     }
    //     printf("\n");
    // }
    char *rome_num;
    rome_num = solution(1245);
    printf("%s %d\n", rome_num);
    return 0;
}