#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int* A, int low, int high) {
    struct MinMax minmax, left, right;
    int mid;
    
    if (low == high) {
        minmax.min = A[low];
        minmax.max = A[low];
        return minmax;
    }
    
    if (high == low + 1) {
        if (A[low] > A[high]) {
            minmax.min = A[high];
            minmax.max = A[low];
        } else {
            minmax.min = A[low];
            minmax.max = A[high];
        }
        return minmax;
    }
    
    mid = (low + high) / 2;
    left = findMinMax(A, low, mid);
    right = findMinMax(A, mid + 1, high);
    
    if (left.min < right.min) {
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }
    
    if (left.max > right.max) {
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }
    
    return minmax;
}

int main() {
    int A[50000];
    int n;
    struct MinMax minmax;
    clock_t start, end;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = rand();
    }
    
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    start = clock();
    minmax = findMinMax(A, 0, n - 1);
    end = clock();
    
    printf("Minimum element: %d\n", minmax.min);
    printf("Maximum element: %d\n", minmax.max);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    
    return 0;
}