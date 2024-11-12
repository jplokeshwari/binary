#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
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
void displayTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    displayTree(root->left, space);
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Binary Tree:\n");
    displayTree(root, 0);
    root = deleteNode(root, 20);
    printf("\nAfter deleting 20:\n");
    displayTree(root, 0);
    root = deleteNode(root, 30);
    printf("\nAfter deleting 30:\n");
    displayTree(root, 0);
    root = deleteNode(root, 50);
    printf("\nAfter deleting 50:\n");
    displayTree(root, 0);
    return 0;
}
