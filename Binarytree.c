



#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Search Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    // If the data is smaller, insert in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the data is greater, insert in the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    // If the data is smaller, search in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }
    
    // If the data is greater, search in the right subtree
    return search(root->right, data);
}

// Function to find the node with the minimum value
struct Node* minValueNode(struct Node* root) {
    struct Node* current = root;
    
    // Loop to find the leftmost leaf node
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }

    // If the data to be deleted is smaller, it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater, it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is the same as root's data, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform an in-order traversal of the tree (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
   printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert a number\n");
        printf("2. Search for a number\n");
        printf("3. Delete a number\n");
        printf("4. In-order Traversal\n");
        printf("5. Exit\n");
    while (1) {
     
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST.\n", value);
                break;

            case 2:
                printf("Enter the number to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 3:
                printf("Enter the number to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted from the BST.\n", value);
                break;

            case 4:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}




