#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
};

// Initialize the queue
struct CircularQueue* createQueue(int k) {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->size = k;
    q->arr = (int*)malloc(k * sizeof(int));
    q->front = q->rear = -1;
    return q;
}

// Check if queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

// Check if queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Standard Enqueue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
}

// Standard Dequeue (Returns the value)
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) return -1;
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

// Display elements from front to rear
void display(struct CircularQueue* q) {
    if (isEmpty(q)) return;
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    int n, m, val;
    
    // 1. Read size/elements
    if (scanf("%d", &n) != 1) return 0;
    struct CircularQueue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    // 2. Read number of rotations (dequeue and re-enqueue)
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }

    // 3. Output
    display(q);

    return 0;
}