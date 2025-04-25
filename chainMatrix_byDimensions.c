#include <stdio.h>
#include <time.h>

void matrixChainOrder(int dims[], int n) {
    int m[100][100], s[100][100];
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 9999;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimum number of scalar multiplications: %d\n", m[1][n - 1]);
    printf("Values of k (split points):\n");
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i][j] != 0) {
                printf("k for m[%d][%d]: %d\n", i, j, s[i][j]);
            }
        }
    }
}

int main() {
    int n;
    clock_t start, end;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int dims[n + 1];
    printf("Enter the dimensions of the matrices (as pairs):\n");
    for (int i = 0; i < n; i++) {
        int rows, cols;
        scanf("%d %d", &rows, &cols);
        if (i == 0) {
            dims[0] = rows;
        }
        dims[i + 1] = cols;
    }
    start = clock();
    matrixChainOrder(dims, n + 1);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}