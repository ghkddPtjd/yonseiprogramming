#include <stdio.h>
int main()
{
 int a = 2;
 float a2 = 2.0;
 int b = 3;
 float c = 3.0;
 printf("a % b: %d\n", a % b);
 printf("a %%% c: %f\n", a % (int)c);
 printf("a2 %%% b: %f\n", a);

 return 0;
}