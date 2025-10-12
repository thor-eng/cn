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

    // Initialize distance and next hop
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
    int iteration = 1;

    do {
        updated = 0;
        printf("\n=== Iteration %d ===\n", iteration++);

        // Print current routing tables
        for (int i = 0; i < n; i++) {
            printf("\nRouting Table for Node %d:\n", i);
            printf("Dest\tNextHop\tDistance\n");
            for (int j = 0; j < n; j++) {
                if (i != j)
                    printf("%d\t%d\t%d\n", j, nextHop[i][j], dist[i][j]);
            }
        }

        // Update phase (distance vector exchange)
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

    // Final tables after convergence
    printf("\n=== Final Routing Tables ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i);
        printf("Dest\tNextHop\tDistance\n");
        for (int j = 0; j < n; j++) {
            if (i != j)
                printf("%d\t%d\t%d\n", j, nextHop[i][j], dist[i][j]);
        }
    }

    return 0;
}
