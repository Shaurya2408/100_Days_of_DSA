#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create/append to a circular linked list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Points to itself
        return newNode;
    }

    struct Node* temp = head;
    // Find the last node (the one that points back to head)
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // Close the circle
    return head;
}

// Function to traverse and print the circular list
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we wrap back to the start
    printf("\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Build the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Output the list
    display(head);

    return 0;
}