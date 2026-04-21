#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

// Initialize the heap
MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain heap property after insertion
void bubbleUp(MinHeap* h, int index) {
    while (index > 0 && h->arr[(index - 1) / 2] > h->arr[index]) {
        swap(&h->arr[(index - 1) / 2], &h->arr[index]);
        index = (index - 1) / 2;
    }
}

// Maintain heap property after extraction
void bubbleDown(MinHeap* h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        bubbleDown(h, smallest);
    }
}

void insert(MinHeap* h, int x) {
    if (h->size == h->capacity) return;
    h->arr[h->size] = x;
    h->size++;
    bubbleUp(h, h->size - 1);
}

int extractMin(MinHeap* h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    bubbleDown(h, 0);
    return root;
}

int peek(MinHeap* h) {
    if (h->size <= 0) return -1;
    return h->arr[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    MinHeap* h = createHeap(n);
    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(h, val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin(h));
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(h));
        }
    }

    free(h->arr);
    free(h);
    return 0;
}