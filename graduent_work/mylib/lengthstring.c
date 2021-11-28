// #include "lengthstring.h"
// Just calculeted lenght strings. BUT, I know it's worth writing like that, I didn't find error, but it is(like). 
int lenstr(const char *str) {
    int len = 0;
    while (*str++)
        len++;
    return len;
}
