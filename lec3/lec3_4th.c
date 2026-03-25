#include <stdio.h>

int main() {
    int digits = 0;
    int n;

    printf("positive integer: ");
    scanf("%d", &n);

    do{
        n = n / 10;
        digits++;

    } while (n > 0);

    printf("digits: %d\n", digits);

    return 0;
}