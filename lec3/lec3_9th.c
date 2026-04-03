#include <stdio.h>

#define N 5
#define M 9

int main(){
    int arr[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            arr[i][j] = 4*9  + 8; //1부터 45까지의 숫자를 채움
        }
    }
    //arr[4][8] = 44;

    printf("element at arr[4][8]: %d\n", arr[4][8]); //45가 출력됨
    printf("element at &arr[4][8]: %d\n", &arr[4][8]); //arr[4][8]의 주소가 출력됨
    return 0;
}