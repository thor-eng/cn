#include <stdio.h>
#include <limits.h>

#define N 100
#define INF 1000000

void dijkstraRowRec(int u, int n, int graph[N][N], int distance[N], int visited[N], int parent[N]) {
    visited[u] = 1;

    // Relax all neighbors in row 'u'
    for (int v = 0; v < n; v++) {
        if (graph[u][v] > 0 && !visited[v]) {
            if (distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u; // record the path
            }
        }
    }

    // Find next unvisited node with minimum distance
    int minDist = INF, next = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && distance[v] < minDist) {
            minDist = distance[v];
            next = v;
        }
    }

    if (next != -1) 
        dijkstraRowRec(next, n, graph, distance, visited, parent);
}

// Recursive path printer
void printPath(int parent[], int j) {
    if (j == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[N][N];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int distance[N], visited[N], parent[N];
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    int src = 0, dest = n - 1;
    distance[src] = 0;

    dijkstraRowRec(src, n, graph, distance, visited, parent);

    printf("\nShortest path from %d to %d: ", src, dest);
    printPath(parent, dest);
    printf("\nShortest distance = %d\n", distance[dest]);

    return 0;
}
