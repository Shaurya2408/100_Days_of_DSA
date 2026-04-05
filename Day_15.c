#include <stdio.h>
int main() {
    int m, n;
    long long sum = 0;
    if (scanf("%d %d", &m, &n) != 2) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value);
            if (i == j) {
                sum += value;
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}