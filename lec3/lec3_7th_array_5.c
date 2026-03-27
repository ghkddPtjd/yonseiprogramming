#include <stdio.h>

int main(){
    char string[10] = "10elementsaaaa";
    //printf("/%s\n", string);

    for (int i = 0; i < 10; i++){
        printf("%c ", string[i]);
    }
    printf("\n");

    
    return 0;
}