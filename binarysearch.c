#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int* A, int n) {
    for(int i = 0; i < n; i++) {
        A[i] = rand() % 50000;
    }
}

void sort(int* A, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int* A, int lo, int hi, int key) {
    if (lo > hi) {
        return -1;
    }
    int mid = (lo + hi) / 2;
    if (A[mid] == key) {
        return mid;
    }
    else if (A[mid] > key) {
        return binarySearch(A, lo, mid - 1, key);
    }
    else {
        return binarySearch(A, mid + 1, hi, key);
    }
}

void display(int* A, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[50000];
    int n, key, pos;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    srand(time(0));
    input(A, n);
    sort(A, n);
    printf("Sorted array: ");
    display(A, n);
    printf("Enter the key to search: ");
    scanf("%d", &key);
    start = clock();
    pos = binarySearch(A, 0, n - 1, key);
    end = clock();
    if (pos == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at position %d\n", pos);
    }
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}