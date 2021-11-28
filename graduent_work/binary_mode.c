#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

enum { CHAR = 0, INTEGER = 1, DOUBLE = 2 };

int reading(char* file, void* data, int len) {
    int fd;
    if ((fd = open(file, O_RDWR)) == -1) {
        printf("error create/open file.\n");
        return -2;
    }
    int check = read(fd, data, len);
    if (check == -1)
        printf("error reading file!\n");
    else if (!check)
        printf("empty file!\n");
    if (close(fd) == -1)
        printf("error closing file\n");
    return check;
}

int writting(char* file, const void* data, int len) {
    int fd;
    if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) == -1) {
        printf("error create file.\n");
        return -2;
    }
    int check = write(fd, data, len);
    if (check == -1)
        printf("failed to write data, to file.\n");
    else if (check != len)
        printf("write error\n\twrite -> %d, and excepted %d\n", check, len);
    if (close(fd) == -1)
        printf("error closing file\n");
    return check;
}

void printtarr(void* arr, int len, const char type) {
    if (type == CHAR) {
        for (int i = 0; i < len; i++)
            printf("%c", *((char*)arr + i));
    }
    else if (type == INTEGER) {
        for (int i = 0; i <= len; i++) {
            printf("%d| ", *((int*)arr + i));
            if (i != 0 && i % 10 == 0)
                printf("\n");
        }
    }
    else if (type == DOUBLE)
        for (int i = 0; i <= len; i++) {
            printf("%.2f | ", *((double*)arr + i));
            if (i != 0 && i % 10 == 0)
                printf("\n");
        }
    printf("\n\n");
}

int main(int argc, char const* argv[]) {
    enum { len = 20 };

    char buff_w_chr[len];
    char buff_r_chr[len];

    int buff_w_int[len];
    int buff_r_int[len];

    double buff_w_dbl[len];
    double buff_r_dbl[len];

    double rangeMin = 20.05;
    double rangeMax = 150.99;

    // fill array's__________________________________________________________________________________________
    for (int i = 0, j = 48; i < len; i++, j++)
        buff_w_chr[i] = j;
    for (int i = 0; i < len; i++)
        buff_w_int[i] = rand() % 25324;
    for (int i = 0; i < len; i++)
        buff_w_dbl[i] = (double)rand() / (double)RAND_MAX * (rangeMax - rangeMin) + rangeMin;
    // ______________________________________________________________________________________________________
    // print w_arrays
    printf("SHOW ARRAYS: _____________________________________________________________________\n");
    printtarr(buff_w_chr, len, CHAR);
    printtarr(buff_w_int, len, INTEGER);
    printtarr(buff_w_dbl, len, DOUBLE);
    printf("__________________________________________________________________________________\n");
    // writting three file
    int wrt_res_chr, wrt_res_int, wrt_res_dbl,
        read_res_chr, read_res_int, read_res_dbl;
    wrt_res_chr = writting("chr(byte).txt", buff_w_chr, len);
    wrt_res_int = writting("int(word).bin", buff_w_int, len * sizeof(int));
    wrt_res_dbl = writting("dbl(dword).bin", buff_w_dbl, len * sizeof(double));
    // result writting
    printf("write chr bytes -> %d\n", wrt_res_chr);
    printf("write int bytes -> %d\n", wrt_res_int);
    printf("write dbl bytes -> %d\n\n", wrt_res_dbl);
    // reading three file
    read_res_chr = reading("chr(byte).txt", buff_r_chr, len);
    read_res_int = reading("int(word).bin", buff_r_int, len * sizeof(int));
    read_res_dbl = reading("dbl(dword).bin", buff_r_dbl, len * sizeof(double));
    // // result reading
    printf("read chr bytes -> %d\n", read_res_chr);
    printf("read int bytes -> %d\n", read_res_int);
    printf("read dbl bytes -> %d\n\n", read_res_dbl);
    // print array read.
    printf("READING FROM FILE: _______________________________________________________________\n");
    printtarr(buff_r_chr, len, CHAR);
    printtarr(buff_r_int, len, INTEGER);
    printtarr(buff_r_dbl, len, DOUBLE);
    printf("__________________________________________________________________________________\n");
    
    // 22.18  | 51.85  | 38.02 | 125.35 | 40.57 | 72.55 | 37.04  | 34.30 | 150.85 | 48.63 | 87.21 | 
    // 129.92 | 100.27 | 58.81 | 103.53 | 88.70 | 84.68 | 147.43 | 58.35 | 121.05 | 0.00  |
    
    // 22.18  | 51.85  | 38.02 | 125.35 | 40.57 | 72.55 | 37.04  | 34.30 | 150.85 | 48.63 | 87.21 | 
    // 129.92 | 100.27 | 58.81 | 103.53 | 88.70 | 84.68 | 147.43 | 58.35 | 121.05 | ??-> 22.18 <-?? | ?????????????????????????
    
    return 0;
}


