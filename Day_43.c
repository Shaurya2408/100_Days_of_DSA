#include <stdio.h>
#include <stdlib.h>

// Define Stack Structure
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Define Queue Structure
struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

// --- Stack Functions ---
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// --- Queue Functions ---
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// --- Main Logic ---
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    struct Queue* queue = createQueue(N);
    struct Stack* stack = createStack(N);

    // Input the queue
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        enqueue(queue, temp);
    }

    // Step 1: Dequeue from Queue and Push to Stack
    while (queue->size > 0) {
        push(stack, dequeue(queue));
    }

    // Step 2: Pop from Stack and Enqueue back to Queue
    while (stack->top != -1) {
        enqueue(queue, pop(stack));
    }

    // Print the reversed queue
    for (int i = 0; i < N; i++) {
        printf("%d%s", dequeue(queue), (i == N - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}