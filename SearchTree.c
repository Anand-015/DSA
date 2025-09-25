#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int main() {
    struct Node* root = NULL;
    struct Node* newNode;
    int value, n;

    // Ask user for the number of nodes to insert
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Insert values into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;

        // If tree is empty, set the new node as root
        if (root == NULL) {
            root = newNode;
        } else {
            struct Node* current = root;
            struct Node* parent = NULL;

            // Find the correct position for the new node
            while (current != NULL) {
                parent = current;
                if (value < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            // Insert the new node as left or right child
            if (value < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

    // Inorder Traversal (Left -> Root -> Right)
    printf("Inorder Traversal: ");
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    // Iterative Inorder Traversal using stack
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");

    // Preorder Traversal (Root -> Left -> Right)
    printf("Preorder Traversal: ");
    top = -1;
    current = root;

    // Iterative Preorder Traversal using stack
    if (current != NULL) {
        stack[++top] = current;
    }

    while (top != -1) {
        current = stack[top--];
        printf("%d ", current->data);
        
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    printf("\n");

    // Postorder Traversal (Left -> Right -> Root)
    printf("Postorder Traversal: ");
    struct Node* lastVisited = NULL;
    top = -1;
    current = root;

    // Iterative Postorder Traversal using stack
    while (top != -1 || current != NULL) {
        if (current != NULL) {
            stack[++top] = current;
            current = current->left;
        } else {
            struct Node* peekNode = stack[top];
            if (peekNode->right != NULL && peekNode->right != lastVisited) {
                current = peekNode->right;
            } else {
                printf("%d ", peekNode->data);
                lastVisited = stack[top--];
            }
        }
    }
    printf("\n");

    return 0;
}
