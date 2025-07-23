#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

void insertion() {
    int value;
    if (front == -1 && rear == -1) {
        front = rear = 0;
        printf("Enter the number: ");
        scanf("%d", &value);
        queue[rear] = value;
    }
    else if (rear == size - 1) {
        printf("Overflow\n");
    }
    else {
        rear++;
        printf("Enter the number: ");
        scanf("%d", &value);
        queue[rear] = value;
    }
}

void deletion() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
      
        }
    }


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    int choice;

    do {
        printf("enter 1 for insertion and 2 for deletion and 3 for display and 4 for existing\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break; 
            case 4:
                printf("existing..");
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice!=4);

    return 0;
}








