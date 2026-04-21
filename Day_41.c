#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the queue structure to track both ends
typedef struct {
    Node *front, *rear;
} Queue;

// Initialize an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Add an element to the back of the queue
void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Remove and return the front element
void dequeue(Queue* q) {
    // If queue is empty
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    // Store previous front and move front one node ahead
    Node* temp = q->front;
    printf("%d\n", temp->data);
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Queue* q = createQueue();
    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue(q);
        }
    }

    return 0;
}