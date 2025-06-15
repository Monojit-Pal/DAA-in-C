#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], n;

void DFS_stack(int start) {
    int stack[MAX], top = -1;
    stack[++top] = start;
    while (top != -1) {
        int vertex = stack[top--];
        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (graph[vertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    DFS_stack(start);

    return 0;
}