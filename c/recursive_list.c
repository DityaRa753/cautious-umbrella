#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    struct item *next;
};

int int_list_sum_two(const struct item *lst)
{
    int sum = 0;
    const struct item *tmp = lst;
    while(tmp) {
        sum += tmp->data;
        tmp = tmp->next;
    }
    return sum;
}

int int_list_sum_three(const struct item *lst) 
{
    int sum = 0;
    const struct item *tmp;
    for(tmp = lst; tmp; tmp = tmp->next) 
        sum += tmp->data;
    return sum;
}

int int_list_sum_four(const struct item *lst) 
{
    int sum = 0;
    for(; lst; lst = lst->next) 
        sum += lst->data;
    return sum;
}

int int_list_sum_five(const struct item *lst)
{
    if(lst)
        return lst->data + int_list_sum_five(lst->next);
    else 
        return 0;
}

int int_list_sum(const struct item *lst)
{
    return lst ? lst->data + int_list_sum(lst->next) : 0;
}

void fillarr(int len, int *arr) {
    for(int i = 1; i <= len+1; i++) {
        arr[i] = i-1;
    }
}

void printarr(int len, int *arr) {
    for (int i = 1; i <= len; i++) {
        if (i % 2 == 1) puts("");
        printf("[%d] => %d\t\t", i, arr[i]);
    }
    puts("");
}

void printlist(const struct item *first) {
    const struct item *tmp = first;
    for (int i = 1; tmp; i++) {
        if(i % 2 == 1 && i != 1) puts("");
        printf("%ld => [%d]\t\t", tmp, tmp->data);
        tmp = tmp->next;
    }
    printf("\nand NULL pnt in last elem. => %ld\n", tmp);
}

struct item *rec_arr_to_list(int len, int *arr) {
    struct item *tmp;
    if (!len)
        return NULL;
    tmp = malloc(sizeof *tmp);
    tmp->data = *arr;
    tmp->next = rec_arr_to_list(len - 1, arr + 1);
    return tmp;
}

int main() {
    struct item *first = NULL;
    enum{len=10};
    int arr[len];
    fillarr(len, arr);
    printarr(len, arr+1);
    first = rec_arr_to_list(len, arr+1);
    printlist(first);
    printf("Sum all elements: %d\n", int_list_sum(first));
    return 0;
}
