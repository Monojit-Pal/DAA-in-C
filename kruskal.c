#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];
    int resultIndex = 0;
    int totalCost = 0;

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (int i = 0; i < E; i++) {
        struct Edge nextEdge = edges[i];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            totalCost += nextEdge.weight;
            unionSets(subsets, x, y);
        }
    }

    printf("\nMinimum Spanning Tree (Kruskal's Algorithm):\n");
    printf("Edge\tWeight\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
    printf("Minimum cost of the tree: %d\n", totalCost);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];
    printf("Enter the edges in the format: source destination weight\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);
    return 0;
}
