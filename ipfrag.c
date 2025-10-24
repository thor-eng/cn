#include <stdio.h>

int main() {
    int msg;
    int mtu;
    printf("enter msg: ");
    scanf("%d", &msg);
    printf("enter mtu: ");
    scanf("%d", &mtu);

    int pkt = msg - 20;   // remove header from total msg
    int mt = mtu - 20;    // remove header from mtu
    int x;
    if ((mt % 8) != 0) {
        x = mt % 8;
        mt = mt - x;      // make mt multiple of 8
    }

    printf("\n--- FRAGMENTATION ---\n");
    printf("frag no\tfrag size\toffset\tmf\n");

    int offset = 0;
    int i = 1;
    int fragments[50];   // to store fragment data sizes (excluding header)
    int fcount = 0;      // count of fragments

    while (pkt > 0) {
        int fragsize;
        int mf;

        if (pkt > mt) {
            fragsize = mt + 20;  // include header
            mf = 1;
        } else {
            fragsize = pkt + 20;
            mf = 0;
        }

        printf("%d\t%d\t\t%d\t%d\n", i, fragsize, offset, mf);

        // store data portion (excluding header)
        fragments[fcount++] = fragsize - 20;

        pkt = pkt - mt;
        offset = offset + (mt / 8);
        i++;
    }

    // --- REASSEMBLY ---
    printf("\n--- REASSEMBLY ---\n");
    printf("Reassembling fragments at destination...\n");

    int total_data = 0;
    for (int j = 0; j < fcount; j++) {
        printf("Received fragment %d: %d bytes of data\n", j + 1, fragments[j]);
        total_data += fragments[j];
    }

    int total_msg = total_data + 20; // add header for reassembled packet
    printf("\nReassembled message size: %d bytes (includes 20-byte header)\n", total_msg);

    return 0;
}
