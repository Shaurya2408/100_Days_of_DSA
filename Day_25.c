#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return head; // Handle allocation failure
    
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to count occurrences of a key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    int n, value, key;
    struct Node* head = NULL;

    // Input: Number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Input: n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Input: Key to count
    scanf("%d", &key);

    // Output: Result
    printf("%d\n", countOccurrences(head, key));

    // Optional: Free memory (Best Practice)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}