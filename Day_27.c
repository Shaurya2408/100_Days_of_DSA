#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to get the length of a linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection based on value (as per the example)
void findIntersection(struct Node* head1, struct Node* head2) {
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    int d = 0;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Align pointers
    if (l1 > l2) {
        d = l1 - l2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = l2 - l1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    // Traverse both simultaneously
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

// Helper to build the list
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int main() {
    int n, m, val;
    struct Node *list1 = NULL, *list2 = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

    findIntersection(list1, list2);

    return 0;
}