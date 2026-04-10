#include <stdio.h>

int main() {
    int abc = 1;
    int* other = &abc;
    int* other2 = other;

    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other2: %d\n", *other2);

    printf("--------------\n");

    abc++;
    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other2: %d\n", *other2);

    printf("--------------\n");

    *other2++;
    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other2: %d\n", *other2);

    printf("--------------\n");

    //연산자 순서 매우 중요함 !! but 괄호 쳐줄 예정
    //괄호 없는데 순서 헷갈리면 여쭤보기. 답변 ㄱㄴ
    
    return 0;

}