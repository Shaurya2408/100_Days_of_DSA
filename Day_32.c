#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Function to display stack elements from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    // 1. Read the number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read n integers and push them
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // 3. Read the number of pops
    if (scanf("%d", &m) != 1) return 0;

    // 4. Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // 5. Output the remaining stack
    display();

    return 0;
}