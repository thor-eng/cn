#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10

// Simulate sending a frame
void sendFrame(int frame, int bit) {
    printf("Sender: Frame %d (Seq=%d) sent.\n", frame, bit);
}

// Simulate receiving an acknowledgment (random success/failure)
int receiveAck(int frame, int bit) {
    int success = rand() % 2; // 0 = lost, 1 = success
    if (success) {
        printf("Receiver: Frame %d received successfully. ACK=%d sent.\n", frame, bit);
    } else {
        printf("Receiver: Frame %d lost! No ACK.\n", frame);
    }
    return success;
}

int main() {
    srand(time(0));

    int frame = 0;
    int bit = 0; // sequence number (0 or 1)

    printf("=== Stop-and-Wait (1-bit Sliding Window) Simulation ===\n");
    printf("Total frames to send: %d\n\n", TOTAL_FRAMES);

    while (frame < TOTAL_FRAMES) {
        sendFrame(frame, bit);

        // Simulate ACK reception
        if (receiveAck(frame, bit)) {
            printf("Sender: ACK %d received. Moving to next frame.\n\n", bit);
            frame++;
            bit = 1 - bit; // Toggle between 0 and 1
        } else {
            printf("Timeout! Resending Frame %d (Seq=%d)\n\n", frame, bit);
            // resend same frame (do not increment frame number)
        }
    }

    printf("All %d frames transmitted successfully!\n", TOTAL_FRAMES);

    return 0;
}
