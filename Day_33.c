#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Function to return precedence of operators
int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    int i, j = 0;
    char postfix[MAX];
    char item, x;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        } 
        else if (item == '(') {
            push(item);
        } 
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        else { // Operator encountered
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    
    if (scanf("%s", infix) != 1) return 0;
    
    infixToPostfix(infix);
    
    return 0;
}