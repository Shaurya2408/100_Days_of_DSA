#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        if (!first) printf(" ");
        printf("%d:%d", arr[i], count);
        first = 0;
    }
    printf("\n");
    free(arr);
    free(visited);
    return 0;
}