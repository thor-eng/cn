#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

// Simulate sending a frame
void sendFrame(int frame) {
    printf("Sender: Frame %d sent.\n", frame);
}

// Simulate receiving acknowledgment (random loss or success)
int receiveAck(int frame) {
    int success = rand() % 2; // 0 = lost, 1 = success
    if (success) {
        printf("Receiver: Frame %d received successfully. ACK sent.\n", frame);
    } else {
        printf("Receiver: Frame %d lost! No ACK.\n", frame);
    }
    return success;
}

int main() {
    srand(time(0));

    int ack[TOTAL_FRAMES] = {0}; // 0 = not acknowledged, 1 = acknowledged
    int sent_upto = 0;           // last frame sent
    int total_acks = 0;          // count of acknowledged frames

    printf("=== Selective Repeat Sliding Window Simulation ===\n");
    printf("Total frames: %d | Window size: %d\n\n", TOTAL_FRAMES, WINDOW_SIZE);

    while (total_acks < TOTAL_FRAMES) {
        // Send all frames in the current window that are not yet ACKed
        for (int i = sent_upto; i < sent_upto + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            if (!ack[i]) { // send only if not already ACKed
                sendFrame(i);
            }
        }

        // Simulate acknowledgments
        for (int i = sent_upto; i < sent_upto + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            if (!ack[i]) {
                if (receiveAck(i)) {
                    ack[i] = 1;
                    total_acks++;
                }
            }
        }

        // Slide window forward if front frames are ACKed
        while (ack[sent_upto] && sent_upto < TOTAL_FRAMES)
            sent_upto++;

        printf("\n---- Current Status ----\n");
        printf("Window starts at frame: %d\n", sent_upto);
        printf("Acknowledged frames: ");
        for (int i = 0; i < TOTAL_FRAMES; i++) {
            printf("%d ", ack[i]);
        }
        printf("\n------------------------\n\n");
    }

    printf("\nAll frames transmitted successfully using Selective Repeat!\n");

    return 0;
}
