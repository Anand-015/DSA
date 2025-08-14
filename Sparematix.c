#include <stdio.h>

// Structure to store one non-zero element
struct Term {
    int row, col, val;
};

int main() {
    struct Term A[50], B[50], C[100], T[50];
    int i, j, k, choice;

    // Step 1: Read first matrix
    printf("Enter rows, cols, non-zero count for A: ");
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].val);
    for (i = 1; i <= A[0].val; i++) {
        printf("Enter row, col, val for A[%d]: ", i);
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].val);
    }

    // Step 2: Read second matrix
    printf("\nEnter rows, cols, non-zero count for B: ");
    scanf("%d %d %d", &B[0].row, &B[0].col, &B[0].val);
    for (i = 1; i <= B[0].val; i++) {
        printf("Enter row, col, val for B[%d]: ", i);
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].val);
    }

    // Step 3: Add A and B → C
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        printf("\nAddition not possible!\n");
        return 0;
    }
    i = j = k = 1;
    while (i <= A[0].val && j <= B[0].val) {
        if ((A[i].row < B[j].row) || 
            (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if ((B[j].row < A[i].row) || 
                 (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else { // same position
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val + B[j].val;
            i++; j++; k++;
        }
    }
    while (i <= A[0].val) C[k++] = A[i++];
    while (j <= B[0].val) C[k++] = B[j++];

    C[0].row = A[0].row;
    C[0].col = A[0].col;
    C[0].val = k - 1;

    // Step 4: Display A, B, C
    printf("\nMatrix A:\nRow Col Val\n");
    for (i = 0; i <= A[0].val; i++)
        printf("%d   %d   %d\n", A[i].row, A[i].col, A[i].val);

    printf("\nMatrix B:\nRow Col Val\n");
    for (i = 0; i <= B[0].val; i++)
        printf("%d   %d   %d\n", B[i].row, B[i].col, B[i].val);

    printf("\nMatrix C (A+B):\nRow Col Val\n");
    for (i = 0; i <= C[0].val; i++)
        printf("%d   %d   %d\n", C[i].row, C[i].col, C[i].val);

    // Step 5: Menu for transpose
    do {
        printf("\n1.Transpose A\n2.Transpose B\n3.Transpose C\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            T[0].row = A[0].col;
            T[0].col = A[0].row;
            T[0].val = A[0].val;
            k = 1;
            for (i = 0; i < A[0].col; i++) {
                for (j = 1; j <= A[0].val; j++) {
                    if (A[j].col == i) {
                        T[k].row = A[j].col;
                        T[k].col = A[j].row;
                        T[k].val = A[j].val;
                        k++;
                    }
                }
            }
            printf("\nTranspose of A:\nRow Col Val\n");
            for (i = 0; i <= T[0].val; i++)
                printf("%d   %d   %d\n", T[i].row, T[i].col, T[i].val);
        }
        else if (choice == 2) {
            T[0].row = B[0].col;
            T[0].col = B[0].row;
            T[0].val = B[0].val;
            k = 1;
            for (i = 0; i < B[0].col; i++) {
                for (j = 1; j <= B[0].val; j++) {
                    if (B[j].col == i) {
                        T[k].row = B[j].col;
                        T[k].col = B[j].row;
                        T[k].val = B[j].val;
                        k++;
                    }
                }
            }
            printf("\nTranspose of B:\nRow Col Val\n");
            for (i = 0; i <= T[0].val; i++)
                printf("%d   %d   %d\n", T[i].row, T[i].col, T[i].val);
        }
        else if (choice == 3) {
            T[0].row = C[0].col;
            T[0].col = C[0].row;
            T[0].val = C[0].val;
            k = 1;
            for (i = 0; i < C[0].col; i++) {
                for (j = 1; j <= C[0].val; j++) {
                    if (C[j].col == i) {
                        T[k].row = C[j].col;
                        T[k].col = C[j].row;
                        T[k].val = C[j].val;
                        k++;
                    }
                }
            }
            printf("\nTranspose of C:\nRow Col Val\n");
            for (i = 0; i <= T[0].val; i++)
                printf("%d   %d   %d\n", T[i].row, T[i].col, T[i].val);
        }

    } while (choice != 4);

    return 0;
}
