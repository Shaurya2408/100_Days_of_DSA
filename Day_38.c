#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

bool isFull(Deque* dq) { return dq->size == MAX; }
bool isEmpty(Deque* dq) { return dq->size == 0; }

void push_front(Deque* dq, int val) {
    if (isFull(dq)) return;
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = val;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    if (isFull(dq)) return;
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = val;
    dq->size++;
}

int pop_front(Deque* dq) {
    if (isEmpty(dq)) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    return val;
}

int pop_back(Deque* dq) {
    if (isEmpty(dq)) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    return val;
}