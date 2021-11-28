#include <stdio.h>
#include <stdlib.h>

int main() {
    struct dbl_item {
        double data;
        struct dbl_item *prev, *next;
    };
    // start, end, current
    struct dbl_item *first = NULL, *last = NULL;
    struct dbl_item *current = NULL, *tmp;
    tmp = malloc(sizeof *tmp);
    tmp->data = x;
    tmp->prev = NULL;
    tmp->next = first;
    if(first)
        first->prev = tmp;
    else
        last = tmp;
    first = tmp;
    return 0;
}
