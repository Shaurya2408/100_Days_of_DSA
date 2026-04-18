#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    // 2. Create the Linked List
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode; // First node is the head
            temp = head;
        } else {
            temp->next = newNode; // Link previous node to new node
            temp = temp->next;    // Move temp to the last node
        }
    }

    // 3. Traverse and Print the list
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // 4. Free memory (Good practice for CSE students!)
    curr = head;
    while (curr != NULL) {
        struct Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }

    return 0;
}