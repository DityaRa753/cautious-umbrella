#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct item *tmp, *tmp2, *first = NULL;
    for (int i = 10; i >= 0; i--) {
        tmp = malloc(sizeof *first);
        tmp->data = arr[i];
        tmp->next = first;
        first = tmp;
    }
    tmp2 = tmp;
    for (int i = 10; i > 0; i--) {
        printf("%d\n", tmp2->data);
        tmp2 = tmp2->next;
    }
}