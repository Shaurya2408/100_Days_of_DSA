#include <stdio.h>
int main() {
    int n, i, j, value;
    int isIdentity = 1;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &value);
            if (i == j) {
                if (value != 1) {
                    isIdentity = 0;
                }
            } else {
                if (value != 0) {
                    isIdentity = 0;
                }
            }
        }
    }
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}