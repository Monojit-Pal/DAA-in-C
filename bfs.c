#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int graph[MAX][MAX], int vertices, int start) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(graph, vertices, start);

    return 0;
}