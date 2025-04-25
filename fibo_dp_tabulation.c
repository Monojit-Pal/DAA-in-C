#include <stdio.h>
#include <time.h>

void fibonacci(int n) {
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d", dp[i]);
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
    fibonacci(n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}