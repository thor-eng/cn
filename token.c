#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bucket_size = 10;        // Maximum tokens in the bucket
    int token_rate = 2;          // Tokens added per time step
    int tokens = 0;              // Current tokens
    int n;                       // Number of time steps
    int incoming, sent, dropped;

    srand(time(0));

    printf("Enter number of time steps: ");
    scanf("%d", &n);

    printf("Time\tTokens\tIncoming\tSent\tDropped\n");
    printf("-----------------------------------------------\n");

    for (int t = 1; t <= n; t++) {
        // Add tokens to the bucket
        tokens += token_rate;
        if (tokens > bucket_size)
            tokens = bucket_size; // Limit to bucket capacity

        // Generate random incoming packets (0–8)
        incoming = rand() % 9;

        // Determine how many packets can be sent
        if (incoming <= tokens) {
            sent = incoming;
            dropped = 0;
            tokens -= sent;
        } else {
            sent = tokens;
            dropped = incoming - tokens;
            tokens = 0;
        }

        printf("%d\t%d\t%d\t\t%d\t%d\n", t, tokens, incoming, sent, dropped);
    }

    return 0;
}
