#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Move the element up to maintain min-heap property
void siftUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[idx] < heap[parent]) {
            swap(&heap[idx], &heap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// Move the element down to maintain min-heap property
void siftDown(int idx) {
    while (idx * 2 + 1 < size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = left;

        if (right < size && heap[right] < heap[left]) {
            smallest = right;
        }

        if (heap[idx] > heap[smallest]) {
            swap(&heap[idx], &heap[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

void insert(int x) {
    if (size < MAX_SIZE) {
        heap[size] = x;
        siftUp(size);
        size++;
    }
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    // The highest priority (smallest) is at the root
    printf("%d\n", heap[0]);
    
    // Replace root with the last element and sift down
    heap[0] = heap[size - 1];
    size--;
    if (size > 0) {
        siftDown(0);
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            deleteMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}