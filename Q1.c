#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choose the last element as the pivot
    int i = low - 1;        // index of the smaller element

    for (int j = low; j < high; j++) {
        // if the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;           
            swap(&arr[i], &arr[j]); 
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;  // seturn the pivot index
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);  // get the pivot index

        // recursively sort the elements before and after the pivot
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);  // get the size of the array

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);  // call the quicksort function

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}