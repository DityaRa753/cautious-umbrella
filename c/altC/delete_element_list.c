#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};


struct item *createList(int *arr, int len)
{
    struct item *tmp, *first = NULL;
    for (int i = 0; i < len; i++) {
        tmp = malloc(sizeof *tmp);
        tmp->data = arr[i];
        tmp->next = first;
        first = tmp;
    }
    return first;
}

void deleteList(struct item **pcur)
{
    while(*pcur) { /* while what it poingts to is not zero */
        if((*pcur)->data < 0) {
            struct item *tmp = *pcur; /* remember this address */
            *pcur = (*pcur)->next; /* exclude from list */
            free(tmp); 
        } else {
            pcur = &(*pcur)->next; 
        }
    }
}

void printElem(int len, struct item *list)
{
    for (int i = len; i > 0; i--) {
        printf("%d\n", list->data);
        list = list->next; 
    }
}

int main() 
{
    enum {len = 10};
    int arr[] = {1, 2, -55, -2, 77, -10, 7, -1, 9, -19};
    struct item *list = createList(arr, len);
    printElem(len, list);
    // printf("%d\n", list->data);
    deleteList(&list);
    printf("\n");
    printElem(len, list);
    return 0;

}