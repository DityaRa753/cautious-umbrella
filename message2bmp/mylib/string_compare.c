#include "lengthstring.c"

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
}

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
