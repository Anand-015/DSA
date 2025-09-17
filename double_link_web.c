#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[256];
    struct Node* prev;
    struct Node* next;
} Node;

Node* current = NULL; // 

Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newNode->url, url, sizeof(newNode->url) - 1);
    newNode->url[sizeof(newNode->url) - 1] = '\0'; 
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void visitNewPage(const char* url) {
    Node* newNode = createNode(url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        current->next = newNode;
    }
    
    current = newNode;
   
}


void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}


void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}


void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}


void freeList() {
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->prev;
        free(temp);
    }
}

int main() {
    int choice;
    char url[256];

   
    while (1) {
        printf("\nBrowser Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitNewPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting........\n");
                freeList();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
