#include <stdio.h>
#define MAX 100

void matrixChainOrder(int dims[], int n, int m[MAX][MAX], int s[MAX][MAX]) {
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                printf("m[%d][%d] k = %d Cost = %d\n", i, j, k, cost);
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
            printf("=> m[%d][%d] chosen k = %d MinCost = %d\n", i, j, s[i][j], m[i][j]);
        }
    }
}

void printOptimalParenthesization(int i, int j, int s[MAX][MAX]) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesization(i, s[i][j], s);
        printOptimalParenthesization(s[i][j] + 1, j, s);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int dims[MAX];
    int m[MAX][MAX], s[MAX][MAX];
    printf("Enter the dimensions of the matrices (as pairs):\n");
    for (int i = 0; i < n; i++) {
        int rows, cols;
        scanf("%d %d", &rows, &cols);
        if (i == 0) {
            dims[0] = rows;
        }
        dims[i + 1] = cols;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                m[i][j] = 0;
            else
                m[i][j] = 99999999;
            s[i][j] = 0;
        }
    }
    matrixChainOrder(dims, n + 1, m, s);
    printf("Minimum no. of multiplication: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesization(1, n, s);
    printf("\n");
    return 0;
}