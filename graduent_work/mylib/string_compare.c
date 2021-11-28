#include "lengthstring.c"
// *******************************************************
// this primitive compare string's. Return boolean(int).
// fucking func... 
// void compare(const char* str1, const char* str2)
// {
//     int lenstr1 = str1, lenstr2 = str2;
//     while (*str1 && *str1 == *str2) {
//         str1++;
//         str2++;
//     }
//     lenstr1 = str1 - lenstr1;
//     lenstr2 = str2 - lenstr2;
//     printf("lenstr1 = %d\n lenstr2 = %d\n", lenstr1, lenstr2);
// }

/*
running time(three test at a time):
    the calculation string's lenghts -> 0.000128;
    1) equal length, last character is different:
    strcmp  -> 0.0001346;
    strcmp1 -> 0.0000416;(without char's counting)
    strcmp1 -> 0.0000600;(with char's count)
*/

// *****************************************************
// my full-compare string's, maybe not perfect, but mine. 
// Here can check lenght each string's)(not length, but boolean type) and there equivalence(on semantic).
// return minus one minus two, zero, positive. Four options.

// zero - strings are completely identical.
// minus one - str1 less than str2.
// minus two - str2 less than str1.
// positive - semantic's not equal, different position.

// test 
// g = "RJ";
// printf("sym %c mem %d || sym %c mem %d\n", *g, g, *(g+1), g+1);
// *****************************************

// for notation
int strcmp(const char* str1, const char* str2)
{
    int lenstr1, lenstr2;
    lenstr1 = lenstr(str1);
    lenstr2 = lenstr(str2);
    if (lenstr1 == lenstr2) {
        for (int i = 0; i < lenstr1; i++) 
            if (str1[i] != str2[i])
                return i;
    }
    else if (lenstr1 < lenstr2)
        return -1;
    else
        return -2;
    return 0;
    // if (check == -1)
    //     printf("str1 less than str2\n");
    // else if (check == -2) 
    //     printf("str2 less than str1\n");
    // else if (check > 0) 
    //     printf("string are equal length, pos %d\n", check);
    // else 
    //     printf("String are equal\n");
}

// while notation. UPD: probably can be simplefied!
// The Achilles heel ofthis construction is in the extra zero terminator at the end of string.
/* UPD: This is bullshit, in fact, there should not be a zero in string,
and the essence of it does not change either. */

int strcmp1(const char* str1, const char* str2) {
    // int i = 0;
    while (((*str1 != 0) && (*str2 != 0)) && (*str1 == *str2)) {
        // i++;
        str1++;
        str2++;
    }
    if ((*str1 == 0) && (*str2 == 0))
        return 0;
    else
        return 1;
}
/* 
I got an idea to make a fucntion for compare an array of strings with an input string, 
well, in the end, 
I'll foreget about it
*/
// char HELPCOMM[7][10] = {"-h", "--help", "-?", "--coding", "-c" "--encoding", "-e", 0};
// void arrstrcmp(const char *str1, const char **str2, const char lenarrstr, const char lenstrings) 
// {
//     if (lenstr(str1) > lenstrings) {
//         printf("This command is not in the programm\n");
//         return 1;
//     } else {
//         for (int i = 0; i < lenarrstr; i++) {
//             for (int j = 0; j < lenstrings; j++) {
//                 if (str1[j] != str2[i][j]) {
//                     printf("\n");
//                     return 2;
//                 }
//             }
//         }
//     }
//     return 0;
// }
