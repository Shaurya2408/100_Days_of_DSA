#include <stdio.h>
#include <stdlib.h>

// 1. The Structure (Always start with this)
struct Node {
    int data;
    struct Node *left, *right;
};

// 2. Helper to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 3. Level Order Traversal Function
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    // Simple Array Queue (Assume max 100 nodes for the exam)
    struct Node* queue[100];
    int head = 0, tail = 0;

    // Step 1: Enqueue Root
    queue[tail++] = root;

    while (head < tail) {
        // Step 2: Dequeue and Print
        struct Node* current = queue[head++];
        printf("%d ", current->data);

        // Step 3: Enqueue Left Child
        if (current->left != NULL) {
            queue[tail++] = current->left;
        }

        // Step 4: Enqueue Right Child
        if (current->right != NULL) {
            queue[tail++] = current->right;
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);

    return 0;
}