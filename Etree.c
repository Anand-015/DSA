#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX 100

typedef struct Node {

char data;

struct Node *left, *right;

} Node;

char opStack[MAX];

int opTop = -1;

void pushOp(char ch) {

if (opTop < MAX - 1)

opStack[++opTop] = ch;

}

char popOp() {

if (opTop >= 0)

return opStack[opTop--];

return '\0';

}

char peekOp() {

if (opTop >= 0)

return opStack[opTop];

return '\0';

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

int isOperand(char ch) {

return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');

}

int isOperator(char ch) {

return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';

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
return op == '^';

}

Node* createNode(char data) {

Node* newNode = (Node*)malloc(sizeof(Node));

newNode->data = data;

newNode->left = newNode->right = NULL;

return newNode;

}

Node* buildExpressionTree(char* infix) {

int i;

char ch;

for (i = 0; i < strlen(infix); i++) {

ch = infix[i];

if (ch == ' ') continue;

if (ch == '(') {

pushOp(ch);

}

else if (isOperand(ch)) {

Node* operandNode = createNode(ch);

pushNode(operandNode);

}

else if (ch == ')') {

while (peekOp() != '(') {

char op = popOp();

Node* right = popNode();

Node* left = popNode();

Node* opNode = createNode(op);

opNode->left = left;

opNode->right = right;

pushNode(opNode);

}

popOp();

}

else if (isOperator(ch)) {

while (opTop != -1 && peekOp() != '(' &&

(precedence(ch) < precedence(peekOp()) ||

(precedence(ch) == precedence(peekOp()) && !isRightAssociative(ch)))) {

char op = popOp();

Node* right = popNode();

Node* left = popNode();

Node* opNode = createNode(op);

opNode->left = left;

opNode->right = right;

pushNode(opNode);

}

pushOp(ch);

}

}

while (opTop != -1) {

char op = popOp();

Node* right = popNode();

Node* left = popNode();
Node* opNode = createNode(op);

opNode->left = left;

opNode->right = right;

pushNode(opNode);

}

return popNode();

}

void printPostorder(Node* root) {

if (root == NULL) return;

printPostorder(root->left);

printPostorder(root->right);

printf("%c", root->data);

}

void freeTree(Node* root) {

if (root == NULL) return;

freeTree(root->left);

freeTree(root->right);

free(root);

}

int main() {

char infix[MAX];

printf("Enter infix expression: ");

scanf("%s", infix);

Node* root = buildExpressionTree(infix);

printf("Postfix expression using expression tree: ");

printPostorder(root);

printf("\n");

freeTree(root);

return 0;

}
