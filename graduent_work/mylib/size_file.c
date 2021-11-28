#include <stdio.h>
#include <fcntl.h>

int filesize(int descriptor)
{
    int buff[1000];
    return read(descriptor, buff, sizeof buff);
}

int availableSize(char encbit, int lenstr, int file_des_txt, int frombmp)
{
    if (!lenstr) {
        // this for -M key, text from file.
    } else {
        // this for -m key.
        printf("%d\n", filesize(frombmp));
    }
    return 0;
}
