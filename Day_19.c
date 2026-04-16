#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    if (n < 2) return;

    // 1. Sort the array: O(n log n)
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_abs_sum = INT_MAX;
    int pair1, pair2;

    // 2. Two-pointer traversal: O(n)
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if current sum is closer to zero
        if (abs(sum) < min_abs_sum) {
            min_abs_sum = abs(sum);
            pair1 = arr[left];
            pair2 = arr[right];
        }

        // Move pointers based on sum
        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else 
            break;
        }
    }
    printf("%d %d\n", pair1, pair2);
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findClosestToZero(arr, n);
    return 0;
}