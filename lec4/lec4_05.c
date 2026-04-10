#include <stdio.h>
/**
 * @brief Calculate sum of array.
 *
 * @param arr array
 * @param arr_size size of the array.
 * @return int sum of array.
 */
int sumOfArray1(int arr[], int arr_size);
/**
 * @brief Calculate sum of array.
 *
 * @param arr array
 * @return int sum of array.
 */
int sumOfArray2(int arr[]);
int main() {
 int arr[5] = { 1, 3, 9, 2, 7 };
 printf("Sum of array using sumOfArray1 is: %d\n"
, sumOfArray1(arr, 5));
 printf("Sum of array using sumOfArray2 is: %d\n"
, sumOfArray2(arr));
return 0;
}
int sumOfArray1(int arr[], int arr_size) {
 return 0;
}
int sumOfArray2(int arr[]) {
 return 0;
} 