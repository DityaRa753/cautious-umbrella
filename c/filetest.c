#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *f;
    f = fopen("file.txt", "r");
    fprintf(stderr, "This is abitrary message!\n");
    if(!f) {
        perror("file.txt");
        exit(1);
    }
    fclose(f);
    return 0;
}
