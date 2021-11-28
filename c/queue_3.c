#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct item *first=NULL, *last=NULL, *tmp, *tmp2;
    for (int i = 0; i < 10; i++) {
        tmp = malloc(sizeof *first);
        tmp->data = arr[i];
        tmp->next = NULL;
        if (last) {
            last->next = tmp;
            last = tmp;
        } else {
            first = last = tmp;
        }
    }
    
    tmp2 = first;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", tmp2->data);
        tmp2 = tmp2->next;
    }
}