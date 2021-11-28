#include <stdio.h>
#include <stdlib.h>

void printarr(const int* arr, const int length) {
    printf("%d ", *arr);
    for (int i = 1; i < length; i++) {
        printf("%d ", arr[i]);
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void swap(int* arr1, int* arr2)
{
    *arr1 = *arr1 + *arr2;
    *arr2 = *arr1 - *arr2;
    *arr1 = *arr1 - *arr2;
}

void selsort(int* arr, const int length)
{
    for (int i = length; i >= 0; i--) {
        int m = i;
        for (int j = length-1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                swap(arr+i, arr+j);
            }
        }
    }
}

int main()
{
    enum { lengArr = 150 };
    int* array[lengArr];
    for (int i = 0; i < lengArr; i++)
        array[i] = rand() % 100;
    printf("unsorted array:\n");
    printarr(array, lengArr);
    selsort(array, lengArr);
    printf("sorted array:\n");
    printarr(array, lengArr);
    return 0;
}
