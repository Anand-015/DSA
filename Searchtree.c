#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

   
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
   
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    

    return search(root->right, data);
}


struct Node* minValueNode(struct Node* root) {
    struct Node* current = root;
    
 
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}


struct Node* deleteNode(struct Node* root, int data) {
 
    if (root == NULL) {
        return root;
    }

 
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
   
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
  
    else {
    
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

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

     
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


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
   printf("\n Binary Search Tree \n");
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








