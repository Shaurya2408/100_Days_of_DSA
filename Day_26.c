#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the end of the DLL
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node
    temp->next = newNode;
    newNode->prev = temp; // Set the backward link

    return head;
}

// Function to traverse and print from head to tail
void displayForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Build the list based on input
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Output the list in forward order
    displayForward(head);

    // Free memory (Recommended practice)
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }

    return 0;
}