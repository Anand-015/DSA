#include <stdio.h>

void bubbleSort(int arr[], int n, int *steps) {
    
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            (*steps)++;  
            if (arr[j] > arr[j + 1]) {
              
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                *steps += 3;  
            }
        }
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

    
    bubbleSort(arr, n, &steps);

   
    printf("Sorted array: ");
    printArray(arr, n);

    
    printf("Bubble Sort steps: %d\n", steps);

    return 0;
}
