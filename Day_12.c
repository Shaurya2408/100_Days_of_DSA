#include <stdio.h>
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int isSymmetric = 1; // Flag: 1 for true, 0 for false
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }
    return 0;
}