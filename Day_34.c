#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        // If token is an operator
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            
            switch (token[0]) {
                case '+': push(&stack, op1 + op2); break;
                case '-': push(&stack, op1 - op2); break;
                case '*': push(&stack, op1 * op2); break;
                case '/': push(&stack, op1 / op2); break;
            }
        } 
        // If token is a number
        else {
            push(&stack, atoi(token));
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    // Use fgets to read the entire line including spaces
    if (fgets(exp, sizeof(exp), stdin)) {
        // Remove trailing newline if present
        exp[strcspn(exp, "\n")] = 0;
        printf("%d\n", evaluatePostfix(exp));
    }
    return 0;
}