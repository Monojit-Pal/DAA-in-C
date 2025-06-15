#include <stdio.h>

int getPascalValue(int i, int j, int triangle[100][100]) {
    if (j == 0 || j == i) {
        return 1;
    }
    return triangle[i - 1][j - 1] + triangle[i - 1][j];
}

void generatePascalTriangle(int n) {
    int triangle[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = getPascalValue(i, j, triangle);
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of levels for Pascal's Triangle: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input. n must be between 1 and 100.\n");
        return 1;
    }
    generatePascalTriangle(n);
    return 0;
}