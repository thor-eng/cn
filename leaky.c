#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bucket_size = 10;       // Maximum capacity of the bucket
    int output_rate = 1;        // Packets sent per time unit
    int storage = 0;            // Current packets in the bucket
    int n;                      // Number of time steps
    int incoming, dropped, sent;

    // Initialize random number generator
    srand(time(0));

    printf("Enter number of time steps: ");
    scanf("%d", &n);

    printf("Time\tIncoming\tStorage\tSent\tDropped\n");
    printf("-------------------------------------------------\n");

    for (int t = 1; t <= n; t++) {
        // Generate a random number of incoming packets (0 to 8)
        incoming = rand() % 9;
        dropped = 0;

        // Check if incoming packets fit in the bucket
        if (storage + incoming <= bucket_size) {
            storage += incoming;
        } else {
            dropped = (storage + incoming) - bucket_size;
            storage = bucket_size;
        }

        // Send packets at the fixed output rate
        sent = (storage >= output_rate) ? output_rate : storage;
        storage -= sent;

        printf("%d\t%d\t\t%d\t%d\t%d\n", t, incoming, storage, sent, dropped);
    }

    return 0;
}
