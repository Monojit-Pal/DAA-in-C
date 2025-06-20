#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int* A, int n) {
    for(int i = 0; i < n; i++) {
        A[i] = rand() % 50000;
    }
}

int partition(int* A, int low, int high) {
    int mid = (low + high) / 2;
    int pivot = A[mid];
    int i = low - 1;
    int temp;
    temp = A[mid];
    A[mid] = A[high];
    A[high] = temp;

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return i + 1;
}

void quicksort(int* A, int low, int high) {
    int partitionIndex;
    if (low < high) {
        partitionIndex = partition(A, low, high);
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
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
    quicksort(A, 0, n - 1);
    end = clock();
    
    printf("\nSorted array: ");
    display(A, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    
    return 0;
}