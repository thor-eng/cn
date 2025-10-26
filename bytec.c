#include <stdio.h>
#include <string.h>

void byte_count(char data[]) {
    int len = strlen(data);
    int count = len ;
    printf("Frame: %d%s\n", count, data);
}

int main() {
    int n;
    printf("Enter number of frames: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char data[200];
        printf("Enter data for frame %d: ", i + 1);
        scanf("%s", data);
        byte_count(data);
    }

    return 0;
}
