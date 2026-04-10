#include <stdio.h>

/// @brief Get the average of two numbers
/// @param a The first number
/// @param b The second number
/// @return The average of a and b

double get_average(double a, double b) {
    return (a + b) / 2.0;
}

int main(){
    double avg = get_average(a:5.0, b:10.0);
    return 0;
}