#include<stdio.h>
#include<string.h>

#define FLAG "01111110"

void bit_stuf(char data[]){
    char stuffed[500];
    int i = 0, count = 0, j = 0;

    // Start flag
    strcpy(stuffed, FLAG);
    j = strlen(FLAG);

    while (data[i] != '\0') {
        stuffed[j++] = data[i];

        if(data[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        if(count == 5) {
            stuffed[j++] = '0'; // Stuff a '0' after five consecutive '1's
            count = 0;
        }

        i++;
    }

    // End flag
    strcpy(&stuffed[j], FLAG);

    printf("Stuffed bit stream: %s\n", stuffed);
}

int main(){
    char data[200];
    scanf("%s", data);
    bit_stuf(data);
    return 0;
}
