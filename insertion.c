#include <stdio.h>

void insertionSort(int arr[], int n, int *steps) {
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];  
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*steps)++;
            arr[j + 1] = arr[j];  
            (*steps)++;  
            j--;
        }
        arr[j + 1] = key;  
        (*steps)++;  
    }
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


    insertionSort(arr, n, &steps);

    
    printf("Sorted array: ");
    printArray(arr, n);

    printf("Insertion Sort steps: %d\n", steps);

    return 0;
}
