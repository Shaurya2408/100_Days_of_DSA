#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rotate the list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // 1. Find length and the actual tail
    struct Node* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // 2. Handle cases where k >= n
    k = k % n;
    if (k == 0) return head;

    // 3. Make the list circular
    tail->next = head;

    // 4. Find the new tail (n - k steps from head)
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    // 5. Set the new head and break the circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Helper: Insert at end for building the list
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val, k;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}