#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Dummy node to simplify logic
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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
    struct Node* mergedHead = mergeSortedLists(list1, list2);
    printList(mergedHead);
    return 0;
}