#include <stdio.h>

int main(){
    printf("3 == 2: %c\n", 3 == 2 ? 't' : 'f');
    printf("3 > 2: %c\n", 3 > 2 ? 't' : 'f');
    printf("3 < 2: %c\n", 3 < 2 ? 't' : 'f');

    (1 * 8 / (3 % 6))+2;
    
    printf("%d\n", 1.0 == 0.1 + 0.9);
    return 0;
}