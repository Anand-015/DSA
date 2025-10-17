#include <stdio.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size, int *steps) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        (*steps)++;  
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }


    while (i < left_size) {
        arr[k++] = left[i++];
    }

    
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n, int *steps) {
    if (n < 2) return;  

    int mid = n / 2;
    int left[mid], right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid, steps);
    mergeSort(right, n - mid, steps);


    merge(arr, left, right, mid, n - mid, steps);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  
    int steps = 0;  

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Original array: ");
    printArray(arr, n);


    mergeSort(arr, n, &steps);


    printf("Sorted array: ");
    printArray(arr, n);

    
    printf("Merge Sort steps: %d\n", steps);

    return 0;
}
