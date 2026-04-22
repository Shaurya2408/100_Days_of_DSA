#include <stdio.h>
#include <stdlib.h>

// --- Queue Implementation ---
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

// --- Stack Implementation (Simple Array) ---
typedef struct {
    int *items;
    int top;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->items = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    return s;
}

void push(Stack* s, int x) {
    s->items[++(s->top)] = x;
}

int pop(Stack* s) {
    return s->items[(s->top)--];
}

// --- Reversal Logic ---
void reverseQueue(Queue* q, int n) {
    Stack* s = createStack(n);

    // Step 1: Queue -> Stack
    while (q->front != NULL) {
        push(s, dequeue(q));
    }

    // Step 2: Stack -> Queue
    while (s->top != -1) {
        enqueue(q, pop(s));
    }

    free(s->items);
    free(s);
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    Queue* q = createQueue();
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    reverseQueue(q, n);

    // Print the reversed queue
    while (q->front != NULL) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    return 0;
}