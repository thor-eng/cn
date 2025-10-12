#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

// Simulate sending a frame
void sendFrame(int frame) {
    printf("Sender: Frame %d sent.\n", frame);
}

// Simulate receiving an acknowledgment
int receiveAck(int frame) {
    // Randomly simulate frame loss or success
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

    int sent_upto = 0; // last frame sent
    int ack = 0;       // last ACK received

    printf("=== Go-Back-N Sliding Window Simulation ===\n");
    printf("Total frames: %d | Window size: %d\n\n", TOTAL_FRAMES, WINDOW_SIZE);

    while (ack < TOTAL_FRAMES) {
        // Send all frames in the current window
        for (int i = 0; i < WINDOW_SIZE && sent_upto < TOTAL_FRAMES; i++) {
            sendFrame(sent_upto);
            sent_upto++;
        }

        // Simulate acknowledgments for the window
        for (int i = ack; i < sent_upto; i++) {
            if (receiveAck(i)) {
                ack++;
            } else {
                printf("\nTimeout! Resending window starting from frame %d\n\n", i);
                sent_upto = i; // Go back to the lost frame
                break;
            }
        }

        printf("---- Current Status ----\n");
        printf("Last ACK received: %d\n", ack - 1);
        printf("------------------------\n\n");
    }

    printf("\nAll frames transmitted successfully!\n");

    return 0;
}
