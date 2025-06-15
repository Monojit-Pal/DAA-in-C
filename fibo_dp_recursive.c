#include <stdio.h>

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
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i + 1, fibonacci(i, dp));
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input. n must be between 1 and 100.\n");
        return 1;
    }
    generateFibonacci(n);
    return 0;
}