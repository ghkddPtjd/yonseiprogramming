#include <stdio.h>

#define MAX_SIZE 100 //최대 입력 가능한 숫자의 개수
#define RANGE 100 //숫자의 범위 (0~99)

int main(){
    int n, i, number;
    int frequency[RANGE] = {0}; //숫자 빈도수를 저장할 배열 초기화
    int arr[MAX_SIZE]; //입력된 숫자를 저장할 배열

    printf("숫자를 입력하세요: ", MAX_SIZE);
    scanf("%d, &n");

    //사용자로부터 nn개의 숫자 입력받기
    for(i = 0; i < n; i++){
        printf("Input %d number: ", i + 1);
        scanf("%d", &number);
        arr[i] = number; //입력된 숫자를 배열에 저장
        if (number >= 0 && number < RANGE){
            frequency[number]++; //숫자의 빈도수 증가
        }
    }

    //빈도수 출력
    printf("숫자 빈도수\n");
    for(i = 0; i < RANGE; i++){
        if (frequency[i] > 0){
            printf("%d: %d\n", i, frequency[i]);
        }
    }


    return 0;
}