#include <stdio.h>
#define INF 9999
#define N 10

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int cost[N][N];
    printf("Enter cost matrix (use %d for no direct link):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int dist[N][N], nextHop[N][N];

    // Initialize distance and next hop tables
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = cost[i][j];
            if (i == j)
                nextHop[i][j] = i;
            else if (cost[i][j] != INF)
                nextHop[i][j] = j;
            else
                nextHop[i][j] = -1;
        }
    }

    int updated;
    // DVR Iterations until no update
    do {
        updated = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        nextHop[i][j] = nextHop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // ✅ Final Converged Routing Tables
    printf("\n=== Final Converged Routing Tables ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i);
        printf("Destination\tNextHop\tDistance\n");
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (dist[i][j] >= INF)
                    printf("%d\t\t-\tINF\n", j);
                else
                    printf("%d\t\t%d\t%d\n", j, nextHop[i][j], dist[i][j]);
            }
        }
    }

    return 0;
}
