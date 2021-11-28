#include <stdio.h>
#include <fcntl.h>

int filesize(int descriptor)
{
    int ans;
    int buff[1000];
    ans = read(descriptor, buff, sizeof buff);
    return ans;
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
