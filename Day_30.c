#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create and insert a node at the end
struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the polynomial in standard form
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Print coefficient and x logic
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Move to next and print " + " if another term exists
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n, c, e;
    struct Node* poly = NULL;

    // Input: number of terms
    if (scanf("%d", &n) != 1) return 0;

    // Input: n pairs of coefficient and exponent
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    // Output the formatted polynomial
    displayPolynomial(poly);

    // Free memory
    while (poly != NULL) {
        struct Node* nextNode = poly->next;
        free(poly);
        poly = nextNode;
    }

    return 0;
}