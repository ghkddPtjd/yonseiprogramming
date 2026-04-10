#include <stdio.h>

int isPrime(int n);

int main(){
    int num = 29;
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

int isPrime(int n){
    return 0; //not Prime
}
