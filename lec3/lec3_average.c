#include <stdio.h>

float average(float input[]);

int main(){
    float a[5] = {100.0, 95.0, 93.0, 90.0, 85.0};
    float b[5] = {60.0, 65.0, 70.0, 75.0, 80.0};

    float c[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};

    float avg = average(a);
    float avg_b = average(b);
    float avg_c = average(c);

    printf("a의 평균: %.2f\n", avg);
    printf("b의 평균: %.2f\n", avg_b);
    printf("c의 평균: %.2f\n", avg_c);
    return  0;
}

float average(float input[]){
    float sum = 0.0;

    //int num = 5; // 평균을 계산할 요소의 개수
    int num = (int) sizeof(input) / sizeof(input[0]); 

    for (int i = 0; i < 5; i++){
        sum += input[i];
    }

    float average = sum / 5;
    
    return average;
}