#include <stdio.h>

int main(){
    int m, n;
    printf("Enter length of generator: ");
    scanf("%d", &m);

    int arr[m];
    printf("Enter generator bits: ");
    for(int i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter length of message: ");
    scanf("%d", &n);

    int msg[n + m - 1]; // message + (m-1) zeros for CRC
    printf("Enter message bits: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &msg[i]);
    }

    // append zeros for CRC
    for(int i = n; i < n + m - 1; i++){
        msg[i] = 0;
    }

    // CRC division
    for(int i = 0; i < n; i++){
        if(msg[i] == 1){
            for(int j = 0; j < m; j++){
                msg[i + j] ^= arr[j];
            }
        }
    }

    printf("CRC bits are: ");
    for(int i = n; i < n + m - 1; i++){
        printf("%d ", msg[i]);
    }
    printf("\n");

    return 0;
}
