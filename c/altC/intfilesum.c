#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    int n, *sum, *count;
    f = fopen("number.txt", "r");
    if(!f) {
        perror("number.txt");
        return 1;
    }
    sum = malloc(sizeof(int));
    count = malloc(sizeof(int));
    /* it would be necessary to check */
    while(fscanf(f, "%d", &n) == 1) {
        *sum += n;
        (*count)++;
    }
    printf("%d %d\n", *sum, *count);
    free(sum);
    free(count);
    fclose(f);
}
