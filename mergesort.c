#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int* A, int n) {
    for(int i = 0; i < n; i++) {
        A[i] = rand() % 50000;
    }
}

void merge(int* A, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[50000];
    
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    
    while (i <= mid) {
        B[k++] = A[i++];
    }
    
    while (j <= high) {
        B[k++] = A[j++];
    }
    
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void mergesort(int* A, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
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
    int n;
    clock_t start, end;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    srand(time(0));
    input(A, n);
    
    printf("Unsorted array: ");
    display(A, n);
    
    start = clock();
    mergesort(A, 0, n - 1);
    end = clock();
    
    printf("\nSorted array: ");
    display(A, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    
    return 0;
}