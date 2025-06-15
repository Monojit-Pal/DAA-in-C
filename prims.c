#include <stdio.h>

#define INF 99999
#define MAX 10

int selectMinVertex(int key[], int mstSet[], int V) {
    int min = INF, vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            vertex = i;
        }
    }
    return vertex;
}

void primsAlgorithm(int graph[MAX][MAX], int V) {
    int parent[MAX], key[MAX], mstSet[MAX];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = selectMinVertex(key, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    int totalCost = 0;
    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Minimum cost of the tree: %d\n", totalCost);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    primsAlgorithm(graph, V);
    return 0;
}
