#include <stdio.h>

//
double get_average(double a, double b) {
    return (a + b) / 2.0;
}

int main(){
    double avg_result = get_average(17.0, 20.0);
    printf("The average of 17.0 and 20.0 is: %.2f\n", avg_result);
    
    int a = 3; //선언과 할당
    //int a; //선언
    //a = 3; //할당
    int b = 8;
    printf("a + b = %d\n", a + b);

    return 0;
}