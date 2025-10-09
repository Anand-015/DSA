
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}
int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return (op == '^');
}
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperand(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1)
                postfix[k++] = pop();
            pop();
        }
        else if (isOperator(ch)) {
            while (isOperator(peek()) &&
                   ((precedence(ch) < precedence(peek())) ||
                    (precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}
Node* nodeStack[MAX];
int nodeTop = -1;

void pushNode(Node* node) {
    if (nodeTop < MAX - 1)
        nodeStack[++nodeTop] = node;
}

Node* popNode() {
    if (nodeTop >= 0)
        return nodeStack[nodeTop--];
    return NULL;
}

Node* newNode(char data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node* constructTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        Node* node = newNode(ch);

        if (isOperand(ch)) {
            pushNode(node);
        } else if (isOperator(ch)) {
            node->right = popNode();
            node->left = popNode();
            pushNode(node);
        }
    }

    return popNode();
}
void printInorder(Node* root) {
    if (root != NULL) {
        if (isOperator(root->data)) printf("(");
        printInorder(root->left);
        printf("%c", root->data);
        printInorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

void printPreorder(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    Node* exprTree = constructTree(postfix);

    printf("Expression tree (Inorder): ");
    printInorder(exprTree);
    printf("\n");

    printf("Preorder traversal: ");
    printPreorder(exprTree);
    printf("\n");

    freeTree(exprTree);
    return 0;
}


