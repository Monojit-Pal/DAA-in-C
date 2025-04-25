#include <stdio.h>
#include <time.h>

void generatePascalTriangle(int n) {
    int triangle[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    clock_t start, end;
    printf("Enter the number of levels for Pascal's Triangle: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input. n must be between 1 and 100.\n");
        return 1;
    }
    start = clock();
    generatePascalTriangle(n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}