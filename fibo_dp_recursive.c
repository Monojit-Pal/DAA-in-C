#include <stdio.h>
#include <time.h>

int fibonacci(int n, int dp[]) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

void generateFibonacci(int n) {
    int dp[100];
    for (int i = 0; i < 100; i++) {
        dp[i] = -1;
    }
    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d", fibonacci(i, dp));
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    clock_t start, end;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input. n must be between 1 and 100.\n");
        return 1;
    }
    start = clock();
    generateFibonacci(n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}