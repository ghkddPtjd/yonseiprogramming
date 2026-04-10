#include <stdio.h>

int isGreaterThan(int a, int b);

int main(){
    int a = 3;
    int b = 5;
    if (isGreaterThan(a, b)) {
        printf("%d is greater than %d\n", a, b);
    } else {
        printf("%d is not greater than %d\n", a, b);
    }

    return 0;
}   

int isGreaterThan(int a, int b) {
    return a > b; //a가 b보다 크면 1(true), 그렇지 않으면 0(false)을 반환
}