#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};

void print_list(struct item *first)
{
    /* I decied to print addresses */
    struct item *tmp = first;
    while(tmp) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
}

struct item *read_write_array()
{
    int chr;
    struct item *first=NULL, *last=NULL, *tmp;
    while ((chr = getchar()) != EOF) {
        tmp = malloc(sizeof *first);
        tmp->data = chr;
        tmp->next = NULL;
        if (last) {
            last->next = tmp;
            last = tmp;
        }
        else {
            first = last = tmp;
        }
    }
    return first;
}


int main() 
{
    struct item *first;
    first = read_write_array();
    print_list(first);
}