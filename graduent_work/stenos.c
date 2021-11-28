/* console application:
1) Step asking user what we are dooing?
this wirte data(text) or read data(text), this question's output in console.
:upd I used command line aruments
Checking input strings
2) Open fucking desctiptor's!!
There are many ways to check file sizem for a good register for win and linux two variable.
Or reinvent the wheel, but need to think, and it will work more slowly, but everywhere.
1 to 1 ; 8 -> 8; 1000b -> 1000file ;
1 to 2 ; 4 -> 8; 1000b -> 2000file ;
1 to 4 ; 2 -> 8; 1000b -> 4000file ;
1 to 8 ; 1 -> 8; 1000b -> 8000file ;
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "mylib/cmdarg.c"

enum { size_buff = 1000 };

int coding() {
    return 0;
}

int encoding(char* buffer, int file_txt, int ibmp, int obmp) {
    // first fifty four bytes, is a sys. bmp information. Copy them. 
    enum { sysbmp = 54 }; // 55 because copy, zero counts too!
    int read_byte = read(ibmp, buffer, sysbmp);
    if (read_byte == -1) {
        printf("failing read.\n");
        return -1;
    }
    else if (!read_byte) {
        printf("reading empty file!\n");
        return -1;
    }
    else {
        int wrt_byte_fifty_four = write(obmp, buffer, sysbmp);
        if (wrt_byte_fifty_four == -1) {
            printf("failing write.\n");
            return -1;
        }
        printf("write bytes -> %d\n", wrt_byte_fifty_four);
        // printf("read bytes -> %u\n", read_byte);
        // for (int i = 0; i < sysbmp; i++)
        //     printf("%c -> %d(%x)  %d\n", buffer[i], buffer[i], buffer[i], i);
        // printf("\n");
    }
    if (!file_txt) {

    }
    else {
        // working with file descriptor.
    }
    return 0;
}

int main(int argc, char** argv) {
    char buffer[size_buff];
    int file_txt = 0, ibmp = 0, obmp = 0, res;
    int doing = cmdarg(argc, argv, &file_txt, &ibmp, &obmp);
    if (doing == 1) {
        res = encoding(buffer, file_txt, ibmp, obmp);
        printf("\nresult -> %d\n", res);
        return 0;
    }
    else if (doing == 2) {
        /* decode here */
        return 0;
    }
    else {
        printf("Oh... fuck error...\n");
        return -1;
    }
}
