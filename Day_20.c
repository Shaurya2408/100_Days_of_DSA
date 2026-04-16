#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    // Pick a starting point
    for (int i = 0; i < n; i++) {
        int current_sum =         for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == 0) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = countZeroSumSubarrays(arr, n);
    printf("%d\n", result);
    return 0;
}