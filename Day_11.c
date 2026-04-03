#include <stdio.h>
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }
    int mat1[m][n];
    int mat2[m][n];
    int sum[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d", sum[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}