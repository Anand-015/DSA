#include <stdio.h>

int partition(int arr[], int low, int high, int *steps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*steps)++;  
        if (arr[j] <= pivot) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            *steps += 3;  
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    *steps += 3; 

    return i + 1;
}

void quickSort(int arr[], int low, int high, int *steps) {
    if (low < high) {

        int pi = partition(arr, low, high, steps);

    
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
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

   
    quickSort(arr, 0, n - 1, &steps);

   
    printf("Sorted array: ");
    printArray(arr, n);

   
    printf("Quick Sort steps: %d\n", steps);

    return 0;
}
