#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};

int strtoint(char *str)
{
    /* zero in ascii -> 48 in decimal; or 0x30 in heximal; */
    int num = 0;
    if(*str < '0' || *str > '9') {
        perror("argument must be a positive number\n");
        exit(2);
    }
    for(; *str; str++)
        num = (num * 10) + (*str - '0');
    return num;
}

void fill_arr(int len, int *arr)
{
    if(len < 1) {
        printf("\nNegative array!\n");
        exit(2);
    }
    for(int i = 1; i <= len; i++)
        arr[i] = i;
}

void print_arr(int len, int *arr)
{
    for(int i = 1; i <= len; i++) {
        if(i % 2 == 1) puts("");
        printf("[%d] => %d\t\t", i, arr[i]);
    }
    puts("");
}

struct item *listqueue(int len, int *arr)
{
    struct item *first = NULL, *last = NULL, *tmp;
    for(int i = 1; i <= len; i++) {
        tmp = malloc(sizeof *first);
        tmp->data = arr[i];
        tmp->next = NULL;
        if(last) { /* from the second iteration */
            last->next = tmp;
            last = tmp;
        } else {
            first = last = tmp;
        }
    }
    return first;
}

void print_list(struct item *first)
{
    /* I decied to print addresses */
    struct item *tmp = first;
    char i = 1;
    while(tmp) {
        if(i % 2 == 1) puts("");
        printf("%ld => [%d]\t\t", tmp, tmp->data);
        tmp = tmp->next;
        i++;
    }
    printf("\nand NULL pnt in last elem. => %ld\n", tmp);
}

int main(argc, argv)
    int argc;
    char **argv;
{
    /* handling possible errors */
    if(argc > 2) return 1;
    if(argc < 2) {
        perror("Too few arguments!\n");
        return 3;
    }
    int len = strtoint(argv[1]);
    /*printf("len->%d", len);*/
    int array[len];
    fill_arr(len, array);
    struct item *first_item = NULL;

    printf("This is array");
    print_arr(len, array);
    printf("sizeof(%ld)\n", sizeof *first_item);
    printf("...and this is list in queue");
    first_item = listqueue(len, array); /* create list */
    print_list(first_item); /* print obviously... */
}
