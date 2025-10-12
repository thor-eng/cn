#include<stdio.h>
#include<string.h>

#define FLAG '~'
#define ESC '\\'

void char_stuffing(char data[]){
    char stuffed[200];
    int i = 0, j = 0;

    stuffed[j++] = FLAG;  // start flag

    for(i = 0; i < strlen(data); i++){
        if(data[i] == FLAG || data[i] == ESC){
            stuffed[j++] = ESC;  // escape character
        }
        stuffed[j++] = data[i];
    }

    stuffed[j++] = FLAG;  // end flag
    stuffed[j] = '\0';

    printf("stuffed data: %s\n", stuffed);
}

int main(){
    char data[100];
    printf("enter data: ");
    scanf("%s", data);
    char_stuffing(data);
    return 0;
}
